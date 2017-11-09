/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_game_movement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:19:26 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/24 15:19:27 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ft_game_ctrl_spr(double ct, const Uint8 *ks, t_pl *pl, double spr)
{
	double	spr_spd;

	spr_spd = pl->mv_sp;
	if (ks[SDL_SCANCODE_LSHIFT])
		if (ft_stat_check(&pl->st.st, pl->st.st.val, STAT_MIN) == 1)
		{
			spr_spd *= spr;
			ft_stat_mod(&pl->st.st, &pl->st.deg, ct);
		}
	return (spr_spd);
}

void	ft_gctrl_mv_frw(t_pl *pl, const Uint8 *ks, double ct, t_map *map)
{
	double	c_mvspd;
	t_v2d	mvr;

	if (ks[SDL_SCANCODE_UP] || ks[SDL_SCANCODE_W])
	{
		c_mvspd = ft_game_ctrl_spr(ct, ks, pl, F_SPR_FORW);
		mvr = ft_game_move_restr(pl->pos, pl->dir, c_mvspd, 1);
		if (ft_game_move_possible(map->m, mvr.x, pl->pos.y, F_WALL_BL) == 1)
			pl->pos.x += pl->dir.x * c_mvspd;
		if (ft_game_move_possible(map->m, pl->pos.x, mvr.y, F_WALL_BL) == 1)
			pl->pos.y += pl->dir.y * c_mvspd;
	}
}

void	ft_gctrl_mv_back(t_pl *pl, const Uint8 *ks, double ct, t_map *map)
{
	double	c_mvspd;
	t_v2d	mvr;

	if (ks[SDL_SCANCODE_DOWN] || ks[SDL_SCANCODE_S])
	{
		c_mvspd = ft_game_ctrl_spr(ct, ks, pl, F_SPR_BACK);
		mvr = ft_game_move_restr(pl->pos, pl->dir, c_mvspd, -1);
		if (ft_game_move_possible(map->m, mvr.x, pl->pos.y, F_WALL_BL) == 1)
			pl->pos.x -= pl->dir.x * c_mvspd;
		if (ft_game_move_possible(map->m, pl->pos.x, mvr.y, F_WALL_BL) == 1)
			pl->pos.y -= pl->dir.y * c_mvspd;
	}
}

void	ft_gctrl_mv_left(t_pl *pl, const Uint8 *ks, t_map *map)
{
	t_v2d	mvr;

	if (ks[SDL_SCANCODE_A])
	{
		mvr = ft_game_move_restr(pl->pos, pl->cam.pos, pl->mv_sp, -1);
		if (ft_game_move_possible(map->m, mvr.x, pl->pos.y, F_WALL_BL) == 1)
			pl->pos.x -= pl->cam.pos.x * pl->mv_sp;
		if (ft_game_move_possible(map->m, pl->pos.x, mvr.y, F_WALL_BL) == 1)
			pl->pos.y -= pl->cam.pos.y * pl->mv_sp;
	}
}

void	ft_gctrl_mv_rght(t_pl *pl, const Uint8 *ks, t_map *map)
{
	t_v2d	mvr;

	if (ks[SDL_SCANCODE_D])
	{
		mvr = ft_game_move_restr(pl->pos, pl->cam.pos, pl->mv_sp, 1);
		if (ft_game_move_possible(map->m, mvr.x, pl->pos.y, F_WALL_BL) == 1)
			pl->pos.x += pl->cam.pos.x * pl->mv_sp;
		if (ft_game_move_possible(map->m, pl->pos.x, mvr.y, F_WALL_BL) == 1)
			pl->pos.y += pl->cam.pos.y * pl->mv_sp;
	}
}
