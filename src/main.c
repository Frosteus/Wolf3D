/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:22:39 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:22:40 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_rayc	ft_wold_loop_set_ray_cast(t_pl *pl, t_wnd *w)
{
	t_rayc	rc;

	rc.dir = (t_v2d){0, 0};
	rc.del_dist = (t_v2d){0, 0};
	rc.ln_sz = 2 * 1 / (double)w->wid;
	rc.side_dist_x = 0;
	rc.side_dist_y = 0;
	rc.map = (t_p){(int)pl->pos.x, (int)pl->pos.y};
	rc.x = 0;
	rc.hwid = w->wid / 2;
	rc.side = SIDE_LIGHT;
	rc.st_x = 0;
	rc.st_y = 0;
	rc.w_dist = 0;
	rc.tex_lnhei = 0;
	rc.tile = NULL;
	rc.tex_w = 256;
	rc.tex_h = 256;
	rc.wall_x = 0;
	return (rc);
}

void	ft_wolf_raycasting_all(t_wnd *w, t_map *map, t_pl *pl)
{
	t_rayc		rc;

	rc = ft_wold_loop_set_ray_cast(pl, w);
	while (rc.x < w->wid)
	{
		ft_wolf_raycast_find_delta(&rc, pl);
		ft_wolf_raycast_find_side_dist(&rc, pl);
		ft_wolf_raycast_find_hit_block(&rc, pl, map);
		rc.tex_w = rc.tile->side[rc.side]->tex->w;
		rc.tex_h = rc.tile->side[rc.side]->tex->h;
		if (rc.tile->val > 0)
		{
			ft_wolf_raycast_find_wall_dist(&rc, pl, w->hei);
			ft_wolf_raycast_texture(&rc, pl, w);
		}
		rc.x++;
	}
}

void	ft_wolf_draw_sky_and_ground(t_wnd *w, t_tbuff *b, t_pl *pl)
{
	SDL_Rect	rect;

	rect = ft_sdl_rect_set(0, 0, w->wid, pl->cam.h_off_av);
	SDL_RenderCopy(w->r, b->add[AS_SKY]->tex->t, NULL, &rect);
	rect = ft_sdl_rect_set(0, pl->cam.h_off_av, w->wid,
	w->hei - pl->cam.h_off_av);
	SDL_SetRenderDrawColor(w->r, 0x63, 0x75, 0x54, 0x00);
	SDL_RenderFillRect(w->r, &rect);
}

void	ft_wolf3d(void)
{
	t_id	id;
	t_sc	sc;
	t_game	*g;

	sc = SC_MENU;
	ft_init_application_prm(&id);
	g = (t_game *)id.scene[SC_GAME].sc;
	while (id.loop == true)
	{
		if (SDL_PollEvent(&id.lprm->e))
			id.lprm->efl = true;
		else
			id.lprm->efl = false;
		ft_general_keydown_check(&id, &sc);
		ft_loop_regular_operations(id.lprm, g);
		sc = id.scene[sc].fun(sc, id.lprm, id.scene[sc].sc);
		SDL_RenderPresent(id.lprm->wnd->r);
		SDL_RenderClear(id.lprm->wnd->r);
		if (sc == SC_EXIT)
			id.loop = false;
	}
	ft_free_resources(&id);
}

int		main(int argc, char *argv[])
{
	UNUSED(argc);
	UNUSED(argv);
	ft_putstr("This wolf is working on its own.");
	ft_sdl_project_exec(ft_wolf3d, NULL);
	return (0);
}
