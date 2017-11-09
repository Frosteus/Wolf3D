/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycasting_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:01:34 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 16:01:35 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_wolf_raycast_find_delta(t_rayc *rc, t_pl *pl)
{
	double sqr_r_dirx;
	double sqr_r_diry;
	double cam_x;

	cam_x = rc->x * rc->ln_sz - 1;
	rc->dir.x = pl->dir.x + pl->cam.pos.x * cam_x;
	rc->dir.y = pl->dir.y + pl->cam.pos.y * cam_x;
	rc->map.x = (int)pl->pos.x;
	rc->map.y = (int)pl->pos.y;
	sqr_r_dirx = rc->dir.x * rc->dir.x;
	sqr_r_diry = rc->dir.y * rc->dir.y;
	rc->del_dist.x = sqrt(1 + sqr_r_diry / sqr_r_dirx);
	rc->del_dist.y = sqrt(1 + sqr_r_dirx / sqr_r_diry);
}

void	ft_wolf_raycast_find_side_dist(t_rayc *rc, t_pl *pl)
{
	if (rc->dir.x < 0)
	{
		rc->st_x = -1;
		rc->side_dist_x = (pl->pos.x - rc->map.x) * rc->del_dist.x;
	}
	else
	{
		rc->st_x = 1;
		rc->side_dist_x = (rc->map.x + 1.0 - pl->pos.x) * rc->del_dist.x;
	}
	if (rc->dir.y < 0)
	{
		rc->st_y = -1;
		rc->side_dist_y = (pl->pos.y - rc->map.y) * rc->del_dist.y;
	}
	else
	{
		rc->st_y = 1;
		rc->side_dist_y = (rc->map.y + 1.0 - pl->pos.y) * rc->del_dist.y;
	}
}

void	ft_wolf_raycast_find_hit_block(t_rayc *rc, t_pl *pl, t_map *map)
{
	t_bool	hit;

	hit = false;
	while (hit == false)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->del_dist.x;
			rc->map.x += rc->st_x;
			rc->side = SIDE_LIGHT;
		}
		else
		{
			rc->side_dist_y += rc->del_dist.y;
			rc->map.y += rc->st_y;
			rc->side = SIDE_DARK;
		}
		if (map->m[rc->map.x][rc->map.y].val > 0)
		{
			hit = true;
			rc->tile = ft_map_get_tile(map, rc->map.x, rc->map.y);
			if (rc->x == rc->hwid)
				pl->targ = ft_target_set(TARG_TILE, rc->map.x, rc->map.y);
		}
	}
}

void	ft_wolf_raycast_find_wall_dist(t_rayc *rc, t_pl *pl, int w_hei)
{
	if (rc->side == SIDE_LIGHT)
		rc->w_dist = (rc->map.x - pl->pos.x + (1 - rc->st_x) / 2) / rc->dir.x;
	else
		rc->w_dist = (rc->map.y - pl->pos.y + (1 - rc->st_y) / 2) / rc->dir.y;
	rc->tex_lnhei = (int)(w_hei / rc->w_dist);
	if (rc->tex_lnhei == 0)
		ft_errors_general(ERR_DIV_ZERO);
}

void	ft_wolf_raycast_texture(t_rayc *rc, t_pl *pl, t_wnd *w)
{
	int			tex_x;
	int			half_line_hei;

	half_line_hei = rc->tex_lnhei / 2;
	rc->dr_st = -half_line_hei + pl->cam.h_off_av;
	rc->dr_end = half_line_hei + pl->cam.h_off_av;
	if (rc->side == SIDE_LIGHT)
		rc->wall_x = pl->pos.y + rc->w_dist * rc->dir.y;
	else
		rc->wall_x = pl->pos.x + rc->w_dist * rc->dir.x;
	rc->wall_x -= floor(rc->wall_x);
	tex_x = (int)(rc->wall_x * rc->tex_w);
	rc->src = RSET(tex_x, 0, 1, rc->tex_h);
	rc->dest = RSET(rc->x, rc->dr_st, 1, rc->dr_end - rc->dr_st);
	SDL_RenderCopy(w->r, rc->tile->side[rc->side]->tex->t, &rc->src, &rc->dest);
	if (rc->tile->eff != NULL)
		SDL_RenderCopy(w->r, rc->tile->eff->tex->t, &rc->src, &rc->dest);
}
