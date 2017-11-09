/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:29:00 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:29:01 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_sdl_destroy_wnd_and_renderer(t_wnd *w)
{
	SDL_DestroyRenderer(w->r);
	SDL_DestroyWindow(w->p);
}

void	ft_free_texture_buffer(t_tbuff *b)
{
	int i;

	i = 1;
	while (i < MAP_TEX + 1)
	{
		ft_sdl_sprite_and_texture_free(b->mtn[i]);
		ft_sdl_sprite_and_texture_free(b->mtd[i]);
		i++;
	}
	free(b->mtn);
	free(b->mtd);
	i = 0;
	while (i < DESTR_TEX)
	{
		ft_sdl_sprite_and_texture_free(b->dt[i]);
		i++;
	}
	free(b->dt);
	ft_tex_additional_free(b);
}

void	ft_free_texture_gui(t_gui *gui)
{
	ft_sdl_sprite_and_texture_free(gui->bs[GUI_CROSS]);
	ft_sdl_sprite_and_texture_free(gui->bs[GUI_HBAR]);
	ft_sdl_sprite_and_texture_free(gui->bs[GUI_HP_BAR]);
	ft_sdl_sprite_and_texture_free(gui->bs[GUI_SBAR]);
	ft_sdl_sprite_and_texture_free(gui->bs[GUI_ST_BAR]);
	ft_sdl_sprite_and_texture_free(gui->bs[GUI_HEART]);
	free(gui->bs);
}

void	ft_free_resources(t_id *id)
{
	t_menu	*m;
	t_game	*g;

	m = id->scene[SC_MENU].sc;
	ft_sdl_panel_free_btn_free(m->p, MENU_BTN_NUM);
	ft_sdl_sprite_and_texture_free(m->bkgrnd_spr);
	free(id->scene[SC_MENU].sc);
	g = id->scene[SC_GAME].sc;
	ft_game_free_maps_and_lvls(g);
	ft_weapon_unload_all_free_inventory(g);
	free(g->pl);
	ft_free_texture_buffer(&g->buff);
	ft_free_texture_gui(&g->gui);
	ft_sdl_spr_buffer_free(g->gfont);
	free(id->scene[SC_GAME].sc);
	free(id->scene);
	ft_sdl_destroy_wnd_and_renderer(id->lprm->wnd);
	free(id->lprm->wnd);
	free(id->lprm);
}
