/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_load_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:53:56 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:53:58 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_weapon_load_doomdoll(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[DOOMDOLL] = ft_weapon_sprites_load(r, 35, "13_Doomdoll");
	w = g->weap[DOOMDOLL];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.6, 0.83}, WEAPON_DEF_SCALE,
	(t_p) {0, 35});
	w->anim[WAIT] = ft_animation_set(0, 1, 50);
	w->anim[SHOOT] = ft_animation_set(1, 35, 80);
	w->anim[RELOAD] = ft_animation_set(1, 35, 50);
}
