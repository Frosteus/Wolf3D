/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:44:24 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:44:25 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_tex_load_additional(t_tbuff *b, t_wnd *w)
{
	if ((b->add = malloc(sizeof(t_spr *) * ADD_SPR_NUM)) == NULL)
		ft_errors_general(ERR_MALLOC);
	b->add[AS_FADE] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_FADE);
	b->add[AS_DIAL] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_DIAL);
	b->add[AS_DIAL]->dest = ft_sdl_rect_set(1, 60, 99, 38);
	b->add[AS_QUEEN] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_QUEEN);
	b->add[AS_SUCCUB] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_SUC);
	b->add[AS_BLOOD] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_BLOOD);
	b->add[AS_GENERAL] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_GENERAL);
	b->add[AS_SKY] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_SKY);
	b->add[AS_GM_OV] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_GM_OV);
	b->add[AS_LOAD] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_LOAD);
	b->add[AS_BIOHAZ] = ft_sdl_sprite_create_from_file(w->r, ADD_SPR_BIOHAZ);
	b->add[AS_BIOHAZ]->dest = ft_sdl_rect_set(1, 78, 6, 8);
	b->add[AS_END] = ft_sdl_sprite_create_from_file(w->r, ADD_END);
}

void	ft_tex_additional_free(t_tbuff *b)
{
	t_addspr	add_spr_iter;

	add_spr_iter = (t_addspr)0;
	while (add_spr_iter < ADD_SPR_NUM)
	{
		ft_sdl_sprite_and_texture_free(b->add[add_spr_iter]);
		add_spr_iter++;
	}
	free(b->add);
}
