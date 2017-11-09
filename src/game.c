/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:02:25 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:02:26 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_game_player_stat_set(t_pl *pl)
{
	pl->hp.st = ft_stat_set(100, 0, 100);
	pl->hp.reg = ft_stat_mod_set(1, STAT_ADD, 1000);
	pl->hp.deg = ft_stat_mod_set(1, STAT_SUB, 200);
	pl->st.st = ft_stat_set(100, 0, 100);
	pl->st.reg = ft_stat_mod_set(1, STAT_ADD, 400);
	pl->st.deg = ft_stat_mod_set(1, STAT_SUB, 100);
}

t_pl	*ft_game_player_create(t_wnd *w)
{
	t_pl	*pl;

	if ((pl = malloc(sizeof(t_pl))) == NULL)
		ft_errors_general(ERR_MALLOC);
	pl->dir.x = 1;
	pl->dir.y = 0;
	pl->cam.pos.x = 0;
	pl->cam.pos.y = -0.7;
	pl->cam.h_off_av = w->hei / 2;
	ft_game_player_stat_set(pl);
	return (pl);
}

void	ft_game_general_prm(t_game *g)
{
	g->sel_w = PISTOL;
	g->d.pos[0] = DRSET(1, 4, 24, 92);
	g->d.pos[1] = DRSET(26, 24, 44, 33);
	g->d.pos[2] = DRSET(26, 43, 70, 94);
	g->d.d_flag = 0;
	g->d.d_tm = 500;
	g->buff.alpha = 255;
	g->c_lvl = LEVEL1;
	g->lvl[LEVEL1].c_lvlp = LVL_START;
	ft_init_lvl1(&g->lvl[LEVEL1]);
	g->lvl[LEVEL2].c_lvlp = LVL_START;
	ft_init_lvl2(&g->lvl[LEVEL2]);
	g->lvl[LEVEL3].c_lvlp = LVL_START;
	ft_init_lvl3(&g->lvl[LEVEL3]);
}

void	ft_game_restart(t_wnd *w, t_game *g)
{
	g->tm = ft_sdl_timer_create();
	ft_game_player_reload(w, g);
	ft_game_lvl_reload(g);
}

t_game	*ft_game_scene_create(t_wnd *w)
{
	t_game *g;

	if ((g = malloc(sizeof(t_game))) == NULL)
		ft_errors_general(ERR_MALLOC);
	ft_gui_set(w, &g->gui);
	g->gfont = ft_font_parse(w->r);
	ft_tex_load_additional(&g->buff, w);
	ft_texture_parser(&g->buff, w->r);
	ft_texture_destr_parser(&g->buff, w->r, DESTR_TEX);
	ft_weapon_create_inventory_load_all(w->r, g);
	if ((g->lvl = malloc(sizeof(t_lvl) * LVL_NUM)) == NULL)
		ft_errors_general(ERR_MALLOC);
	ft_game_general_prm(g);
	g->pl = ft_game_player_create(w);
	return (g);
}
