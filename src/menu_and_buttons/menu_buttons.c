/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:29:59 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:30:02 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_btn	*ft_menu_btn_resume(t_wnd *w)
{
	t_btn		*b;
	t_spr		*spr;
	t_spr		*spr_alt;
	SDL_Rect	r;

	spr = ft_sdl_sprite_create_from_file(w->r, MENU_RESUME_A);
	SDL_SetTextureColorMod(spr->tex->t, 150, 150, 150);
	spr_alt = ft_sdl_sprite_create_from_file(w->r, MENU_RESUME_NA);
	r = ft_sdl_rect_wndrel(w, DRSET(5, 15, 15, 5));
	b = ft_sdl_btn_create(&r, spr, spr_alt, (void *)ft_resume_click);
	ft_sdl_btn_state_set(b, NO_FLAG);
	return (b);
}

t_btn	*ft_menu_btn_new_game(t_wnd *w)
{
	t_btn		*b;
	t_spr		*spr;
	t_spr		*spr_alt;
	SDL_Rect	r;

	spr = ft_sdl_sprite_create_from_file(w->r, MENU_NEW_GAME_A);
	SDL_SetTextureColorMod(spr->tex->t, 150, 150, 150);
	spr_alt = ft_sdl_sprite_create_from_file(w->r, MENU_NEW_GAME_NA);
	r = ft_sdl_rect_wndrel(w, DRSET(5, 21, 20, 5));
	b = ft_sdl_btn_create(&r, spr, spr_alt, (void *)ft_new_game_click);
	return (b);
}

t_btn	*ft_menu_btn_options(t_wnd *w)
{
	t_btn		*b;
	t_spr		*spr;
	t_spr		*spr_alt;
	SDL_Rect	r;

	spr = ft_sdl_sprite_create_from_file(w->r, MENU_OPTIONS_A);
	SDL_SetTextureColorMod(spr->tex->t, 150, 150, 150);
	spr_alt = ft_sdl_sprite_create_from_file(w->r, MENU_OPTIONS_NA);
	r = ft_sdl_rect_wndrel(w, DRSET(5, 27, 18, 5));
	b = ft_sdl_btn_create(&r, spr, spr_alt, (void *)ft_options_click);
	ft_sdl_btn_state_set(b, IS_VISIBLE);
	return (b);
}

t_btn	*ft_menu_btn_exit(t_wnd *w)
{
	t_btn		*b;
	t_spr		*spr;
	t_spr		*spr_alt;
	SDL_Rect	r;

	spr = ft_sdl_sprite_create_from_file(w->r, MENU_EXIT_A);
	SDL_SetTextureColorMod(spr->tex->t, 150, 150, 150);
	spr_alt = ft_sdl_sprite_create_from_file(w->r, MENU_EXIT_NA);
	r = ft_sdl_rect_wndrel(w, DRSET(5, 33, 10, 5));
	b = ft_sdl_btn_create(&r, spr, spr_alt, (void *)ft_exit_click);
	return (b);
}
