/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_text_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:07:28 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:07:31 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

t_text	ft_sdl_text_solid(t_font f, int x, int y)
{
	t_text		t;

	t.f = f;
	t.font = TTF_OpenFont(t.f.fname, t.f.size);
	t.loc = (SDL_Rect) { x, y, 0, 0 };
	return (t);
}

void	ft_sdl_free_text(t_text *t)
{
	TTF_CloseFont(t->font);
	SDL_FreeSurface(t->surf);
}

t_font	ft_sdl_font_prm(const char *fn, int sz, SDL_Color fc, SDL_Color bc)
{
	t_font	f;

	f.fname = fn;
	f.size = sz;
	f.fcol = fc;
	f.bcol = bc;
	return (f);
}

void	ft_sdl_put_text(t_text *t, const char *msg, SDL_Surface *img)
{
	t->surf = TTF_RenderText_Solid(t->font, msg, t->f.fcol);
	SDL_BlitSurface(t->surf, NULL, img, &t->loc);
	SDL_FreeSurface(t->surf);
}
