/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:30:27 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:30:30 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_menu_load_background(SDL_Renderer *r, t_menu *m)
{
	m->bkgrnd_spr = ft_sdl_sprite_create_from_file(r, MENU_BKGRND);
	m->bkgrnd_spr->dest = RSET(0, 0, 0, 0);
}

void	ft_menu_btn_arrange(t_wnd *w, t_menu *menu)
{
	t_btn	*b;

	menu->p->arr = ft_sdl_btn_create_2d_array(4, 1);
	b = ft_menu_btn_resume(w);
	menu->p->arr[0][0] = *b;
	free(b);
	b = ft_menu_btn_new_game(w);
	menu->p->arr[0][1] = *b;
	free(b);
	b = ft_menu_btn_options(w);
	menu->p->arr[0][2] = *b;
	free(b);
	b = ft_menu_btn_exit(w);
	menu->p->arr[0][3] = *b;
	free(b);
}

t_menu	*ft_menu_create(t_wnd *w)
{
	t_menu	*menu;

	if ((menu = malloc(sizeof(t_menu))) == NULL)
		ft_errors_general(ERR_MALLOC);
	ft_menu_load_background(w->r, menu);
	menu->p = ft_sdl_panel_create_empty(RSET(100, 100, 300, 500), 1, 4);
	ft_menu_btn_arrange(w, menu);
	return (menu);
}

t_btn	*ft_menu_btn_selection(t_menu *menu, t_p ms_coord)
{
	t_btn	*b;

	b = ft_sdl_panel_mouse_check(menu->p, ms_coord);
	if (b != NULL)
		SDL_SetTextureColorMod(b->spr[1]->tex->t, 255, 255, 255);
	return (b);
}

void	ft_menu_btn_deselection(t_btn *b)
{
	if (b != NULL)
		SDL_SetTextureColorMod(b->spr[1]->tex->t, 150, 150, 150);
}
