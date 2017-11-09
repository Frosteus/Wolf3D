/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:13:04 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:13:05 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_lvl2_setting_up(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	UNUSED(lprm);
	ft_sdl_sprite_show(g->buff.add[AS_LOAD], NULL, SPR_SPR_TO_SCR);
	g->tm = ft_sdl_timer_create();
	g->pl->dir.x = 1;
	g->pl->dir.y = 0;
	g->pl->cam.pos.x = 0;
	g->pl->cam.pos.y = -0.7;
	g->pl->targ.t = TARG_EMPTY;
	g->sel_w = REPEATER;
	lvl->win_trig = ft_trigger_set(0, 0, T77_ACTIVAT, TRIG_GAME_WON);
	lvl->win_trig.bool = false;
	ft_map_parse(&g->buff, lvl, g->pl);
	lvl->lvl_tm = ft_sdl_timer_create();
	lvl->c_lvlp = LVL_DIAL_EV;
}

void	ft_lvl2_dial_event(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	ft_game_loop_regular_operation(lprm, g, lvl);
	ft_dialog_box_skip(lprm, g, lvl);
	if (g->buff.alpha > 1)
	{
		ft_sdl_sprite_show(g->buff.add[AS_FADE], NULL, SPR_SPR_TO_SCR);
		SDL_SetTextureAlphaMod(g->buff.add[AS_FADE]->tex->t, g->buff.alpha);
		ft_font_txtbox(g->gfont, ft_sdl_rect_wndrel(lprm->wnd,
		DRSET(15, 45, 85, 55)), lvl->name, 0.4);
		SDL_Delay(10);
		g->buff.alpha--;
	}
	else
	{
		ft_lvl2_queen_dialog_1(lprm->wnd, g);
		if (g->d.d_flag >= 2)
		{
			SDL_SetTextureAlphaMod(g->buff.add[AS_FADE]->tex->t, g->buff.alpha);
			lvl->c_lvlp = LVL_PLAY;
			g->d.d_flag = 0;
		}
	}
}

void	ft_lvl2_gameplay(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	g->pl->mv_sp = ft_sdl_timer_get_delta(&g->tm) / 1000. * F_MV;
	g->pl->rot_speed = ft_sdl_timer_get_delta(&g->tm) / 1000. * F_ROT;
	ft_regen_hp_and_stamina(g->pl, g->tm.del_t);
	ft_game_loop_regular_operation(lprm, g, lvl);
	ft_game_controls(lprm, g, lvl);
	ft_game_controls_mouse(lprm, g);
	ft_block_player_damage(lprm->wnd, g, g->pl, &lvl->map);
	ft_weapon_action(lprm, g);
	ft_gui_show(lprm->wnd, &g->gui, g->pl);
	ft_level_part_lvl_num_change(g);
}
