/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_window_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:38:54 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:08:09 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

void	ft_sdl_set_wnd_prm(t_wnd *wnd, int wid, int hei, const char *name)
{
	wnd->wid = wid;
	wnd->hei = hei;
	wnd->name = name;
}

void	ft_sdl_create_window(t_wnd *wnd)
{
	wnd->p = SDL_CreateWindow(wnd->name, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, wnd->wid, wnd->hei, SDL_WINDOW_OPENGL
	| SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	if (wnd->p == NULL)
		ft_sdl_log_errors(WND_CRE_ERR);
	wnd->r = SDL_CreateRenderer(wnd->p, -1, SDL_REND);
}

void	ft_sdl_create_window_and_renderer(t_wnd *wnd)
{
	if (SDL_CreateWindowAndRenderer(wnd->wid, wnd->hei,
	SDL_WINDOW_RESIZABLE, &wnd->p, &wnd->r) == -1)
		ft_sdl_log_errors(WND_REND_CRE_ERR);
}
