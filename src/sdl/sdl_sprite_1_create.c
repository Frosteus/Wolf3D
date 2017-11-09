/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_sprite_1_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:22:10 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:22:14 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

t_spr	ft_sdl_sprite_create_stack(t_tex *tex, SDL_Rect spr)
{
	t_spr	sprite;

	sprite.tex = tex;
	sprite.src = spr;
	return (sprite);
}

t_spr	*ft_sdl_sprite_create_heap(t_tex *tex, SDL_Rect *src)
{
	t_spr	*sprite;

	if ((sprite = malloc(sizeof(t_spr))) == NULL)
		ft_errors_general(ERR_MALLOC);
	sprite->tex = tex;
	if (src == NULL)
		sprite->src = ft_sdl_rect_set(0, 0, tex->w, tex->h);
	else
		sprite->src = *src;
	return (sprite);
}

t_spr	*ft_sdl_sprite_create_from_file(SDL_Renderer *r, const char *fn)
{
	t_spr	*sprite;
	t_tex	*texture;

	texture = ft_sdl_texture_from_image_heap(r, fn);
	sprite = ft_sdl_sprite_create_heap(texture, NULL);
	return (sprite);
}

void	ft_sdl_sprite_and_texture_free(t_spr *spr)
{
	ft_sdl_texture_free_heap(spr->tex);
	free(spr);
}
