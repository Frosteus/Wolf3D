/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_sprite_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:07:00 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:07:01 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

void	ft_sdl_sprite_wnd_box(t_wnd *w, t_spr *spr, t_drect *dst, int mode)
{
	SDL_Rect	r;
	t_drect		dr;

	if (mode == SPR_WND_REL)
	{
		dr = R_TOD(spr->dest);
		r = ft_sdl_rect_wndrel(w, dr);
		SDL_RenderCopy(spr->tex->r, spr->tex->t, &spr->src, &r);
	}
	else if (mode == SPR_CALC_WND_REL && dst != NULL)
	{
		r = ft_sdl_rect_wndrel(w, *dst);
		SDL_RenderCopy(spr->tex->r, spr->tex->t, &spr->src, &r);
	}
}

void	ft_sdl_sprite_show(t_spr *spr, SDL_Rect *dest, int mode)
{
	if (mode == SPR_NORMAL)
		SDL_RenderCopy(spr->tex->r, spr->tex->t, &spr->src, dest);
	else if (mode == SPR_SPR_TO_DEST)
		SDL_RenderCopy(spr->tex->r, spr->tex->t, NULL, dest);
	else if (mode == SPR_SPR_TO_SCR)
		SDL_RenderCopy(spr->tex->r, spr->tex->t, NULL, NULL);
}
