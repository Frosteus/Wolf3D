/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:14:28 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:14:29 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_lvl3_setting_up(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	UNUSED(lprm);
	ft_sdl_sprite_show(g->buff.add[AS_LOAD], NULL, SPR_SPR_TO_SCR);
	g->sel_w = PISTOL;
	g->pl->dir.x = 1;
	g->pl->dir.y = 0;
	g->pl->cam.pos.x = 0;
	g->pl->cam.pos.y = -0.7;
	g->pl->targ.t = TARG_EMPTY;
	lvl->win_trig = ft_trigger_set(0, 0, T77_ACTIVAT, TRIG_GAME_WON);
	lvl->win_trig.bool = false;
	ft_map_parse(&g->buff, lvl, g->pl);
	lvl->lvl_tm = ft_sdl_timer_create();
	lvl->lvl_tm.cur_t = 500;
	lvl->lvl_tm.frm = 0;
	lvl->c_lvlp = LVL_PLAY;
}

void	ft_lvl3_lava_move(t_game *g, t_lvl *lvl)
{
	int		i;
	t_tile	*t;

	lvl->lvl_tm.all_t += g->tm.del_t;
	if (lvl->lvl_tm.all_t > lvl->lvl_tm.cur_t)
	{
		i = 0;
		while (i < lvl->map.w)
		{
			t = ft_map_get_tile(&lvl->map, lvl->lvl_tm.frm, i);
			if ((int)g->pl->pos.x != lvl->lvl_tm.frm || (int)g->pl->pos.y != i)
				if (t->val == 0)
				{
					t->val = T12_LAVA;
					t->side[SIDE_LIGHT] = g->buff.mtn[t->val];
					t->side[SIDE_DARK] = g->buff.mtd[t->val];
					t->hp.st = ft_stat_set(1000, 0, 1000);
					t->hp.deg = ft_stat_mod_set(1, STAT_SUB, 0);
				}
			i++;
		}
		lvl->lvl_tm.all_t = 0;
		if (lvl->lvl_tm.frm < lvl->map.h - 1)
			lvl->lvl_tm.frm++;
	}
}

void	ft_lvl3_gameplay(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	g->pl->mv_sp = ft_sdl_timer_get_delta(&g->tm) / 1000. * F_MV;
	g->pl->rot_speed = ft_sdl_timer_get_delta(&g->tm) / 1000. * F_ROT;
	ft_regen_hp_and_stamina(g->pl, g->tm.del_t);
	ft_lvl3_lava_move(g, lvl);
	ft_game_loop_regular_operation(lprm, g, lvl);
	ft_game_controls(lprm, g, lvl);
	ft_game_controls_mouse(lprm, g);
	ft_block_player_damage(lprm->wnd, g, g->pl, &lvl->map);
	ft_weapon_action(lprm, g);
	ft_gui_show(lprm->wnd, &g->gui, g->pl);
	if (g->pl->pos.x > 81)
		lvl->c_lvlp = LVL_END;
}
