/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:07:41 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:07:42 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

t_tex	*ft_sdl_texture_from_image_heap(SDL_Renderer *r, const char *fn)
{
	t_tex	*texture;

	if ((texture = malloc(sizeof(t_tex))) == NULL)
		ft_errors_general(ERR_MALLOC);
	texture->r = r;
	if ((texture->t = IMG_LoadTexture(r, fn)) == NULL)
		ft_sdl_log_errors(TEX_ERR);
	if (SDL_QueryTexture(texture->t, NULL, NULL, &texture->w, &texture->h))
		ft_sdl_log_errors(TEX_QUERY);
	return (texture);
}

t_tex	*ft_sdl_texture_free_heap(t_tex *tex)
{
	SDL_DestroyTexture(tex->t);
	free(tex);
	return (NULL);
}
