/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_sprite_2_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:32:48 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:32:49 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

t_spr_p	*ft_sdl_sprite2_create_heap(t_tex *tex, SDL_Rect *src)
{
	t_spr_p	*sprite;

	if ((sprite = malloc(sizeof(t_spr_p))) == NULL)
		ft_errors_general(ERR_MALLOC);
	sprite->tex = tex;
	if (src == NULL)
		sprite->src = ft_sdl_rect_set(0, 0, tex->w, tex->h);
	else
		sprite->src = *src;
	return (sprite);
}

t_spr_p	*ft_sdl_sprite2_create_from_file(SDL_Renderer *r, const char *fn)
{
	t_spr_p	*sprite;
	t_tex	*texture;

	texture = ft_sdl_texture_from_image_heap(r, fn);
	sprite = ft_sdl_sprite2_create_heap(texture, NULL);
	return (sprite);
}

void	ft_sdl_spr2_to_point(t_wnd *w, t_spr_p *spr, t_v2d pos, t_v2d sc)
{
	t_drect		dr;
	SDL_Rect	r;
	double		ax;
	double		ay;

	ax = spr->sx * sc.x * spr->tex->w;
	ay = spr->sy * sc.y * spr->tex->h;
	dr.x = (w->wid * pos.x - ax / 2.);
	dr.y = (w->hei * pos.y - ay / 2.);
	dr.w = ax;
	dr.h = ay;
	r = ft_sdl_rect_dbl_to_int(dr);
	SDL_RenderCopy(spr->tex->r, spr->tex->t, &spr->src, &r);
}

void	ft_sdl_sprite2_and_texture_free(t_spr_p *spr)
{
	ft_sdl_texture_free_heap(spr->tex);
	free(spr);
}
