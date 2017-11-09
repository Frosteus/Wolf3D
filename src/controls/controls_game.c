/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:17:46 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/24 15:17:47 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_game_controls_use(t_lprm *lprm, t_game *g, t_pl *pl, t_map *map)
{
	t_tile	*tile;

	if (lprm->efl == false)
		return ;
	if (lprm->e.type == SDL_KEYDOWN && lprm->e.key.keysym.sym == SDLK_e)
		if (pl->targ.t == TARG_TILE)
		{
			tile = ft_map_get_tile(map, pl->targ.x[TARG_TILE],
			pl->targ.y[TARG_TILE]);
			if (tile->val == T77_ACTIVAT)
				g->lvl[g->c_lvl].win_trig.bool = true;
		}
}

void	ft_game_controls(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	t_pl	*pl;

	pl = g->pl;
	ft_game_ctrl_look_up(pl, lprm->ks);
	ft_game_ctrl_look_down(pl, lprm->ks);
	ft_gctrl_mv_frw(pl, lprm->ks, ft_sdl_timer_get_delta(&g->tm), &lvl->map);
	ft_gctrl_mv_back(pl, lprm->ks, ft_sdl_timer_get_delta(&g->tm), &lvl->map);
	ft_gctrl_mv_left(pl, lprm->ks, &lvl->map);
	ft_gctrl_mv_rght(pl, lprm->ks, &lvl->map);
	if (lprm->ks[SDL_SCANCODE_LEFT])
		ft_game_ctrl_rot_left(pl, 1);
	if (lprm->ks[SDL_SCANCODE_RIGHT])
		ft_game_ctrl_rot_right(pl, 1);
	ft_game_controls_weapon(lprm, g);
	ft_game_controls_use(lprm, g, pl, &lvl->map);
}

void	ft_game_controls_mouse(t_lprm *lprm, t_game *g)
{
	t_map	*map;

	if (lprm->efl == false)
		return ;
	if (lprm->e.type == SDL_MOUSEBUTTONDOWN)
	{
		map = &g->lvl[g->c_lvl].map;
		if (lprm->e.button.button == SDL_BUTTON_LEFT)
		{
			if (g->weap[g->sel_w]->w_st == WAIT && g->weap[g->sel_w]->ammo)
				g->weap[g->sel_w]->w_st = SHOOT;
		}
		else if (lprm->e.button.button == SDL_BUTTON_RIGHT)
			ft_gameplay_place_tile(g->pl, map, &g->buff);
	}
	else if (lprm->e.type == SDL_MOUSEMOTION)
	{
		if (lprm->e.motion.xrel < 0)
			ft_game_ctrl_rot_left(g->pl, 2);
		else if (lprm->e.motion.xrel > 0)
			ft_game_ctrl_rot_right(g->pl, 2);
	}
}
