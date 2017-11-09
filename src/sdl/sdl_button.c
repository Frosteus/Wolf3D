/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:05:09 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:05:10 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

t_btn	*ft_sdl_btn_create(SDL_Rect *r, t_spr *s, t_spr *spr_alt, t_fptr f)
{
	t_btn	*b;

	if ((b = malloc(sizeof(t_btn))) == NULL)
		ft_errors_general(ERR_MALLOC);
	b->dest = *r;
	b->f_click = f;
	b->spr[NA_VIEW] = spr_alt;
	b->spr[ABLE_VIEW] = s;
	b->flags = IS_AV;
	return (b);
}

void	ft_sdl_btn_show(t_btn *b, SDL_Rect *dest)
{
	if (b->flags & IS_VISIBLE)
		ft_sdl_sprite_show(b->spr[b->flags & IS_ABLE], dest, SPR_NORMAL);
}

int		ft_sdl_btn_mouse_over_check(int x, int y, t_btn *b)
{
	if (b->flags & IS_AV && x > b->dest.x && y > b->dest.y
	&& x < b->dest.x + b->dest.w && y < b->dest.y + b->dest.h)
		return (1);
	return (0);
}

void	ft_sdl_btn_state_set(t_btn *b, enum e_btn state)
{
	b->flags = state;
}
