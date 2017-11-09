/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:52:00 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:52:01 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_loop_regular_operations(t_lprm *lprm, t_game *g)
{
	lprm->ks = SDL_GetKeyboardState(NULL);
	ft_sdl_window_get_dim(lprm->wnd);
	lprm->xy_sc.x = (double)lprm->wnd->wid / lprm->base_sc.x;
	lprm->xy_sc.y = (double)lprm->wnd->hei / lprm->base_sc.y;
	SDL_GetMouseState(&lprm->ms_coord.x, &lprm->ms_coord.y);
	ft_sdl_timer_calc_delta_and_frame(&g->tm);
}

void	ft_game_loop_regular_operation(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	ft_wolf_draw_sky_and_ground(lprm->wnd, &g->buff, g->pl);
	ft_wolf_raycasting_all(lprm->wnd, &lvl->map, g->pl);
	ft_scene_show_blood_splat(g->buff.add[AS_BLOOD], g->pl);
}
