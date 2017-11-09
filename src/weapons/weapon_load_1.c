/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_load_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:08:32 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 20:08:34 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_weapon_load_pistol(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[PISTOL] = ft_weapon_sprites_load(r, 4, "1_Pistol");
	w = g->weap[PISTOL];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.8, 0.82}, WEAPON_DEF_SCALE,
	(t_p) {0, 4});
	w->anim[WAIT] = ft_animation_set(0, 1, 150);
	w->anim[SHOOT] = ft_animation_set(0, 4, 120);
	w->anim[RELOAD] = ft_animation_set(2, 4, 200);
}

void	ft_weapon_load_repeater(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[REPEATER] = ft_weapon_sprites_load(r, 4, "2_Repeater");
	w = g->weap[REPEATER];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.8, 0.83}, WEAPON_DEF_SCALE,
	(t_p) {0, 4});
	w->anim[WAIT] = ft_animation_set(0, 1, 150);
	w->anim[SHOOT] = ft_animation_set(0, 3, 100);
	w->anim[RELOAD] = ft_animation_set(2, 3, 150);
}

void	ft_weapon_load_hellshot(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[HELLSHOT] = ft_weapon_sprites_load(r, 7, "3_Hellshot");
	w = g->weap[HELLSHOT];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.78, 0.82}, WEAPON_DEF_SCALE,
	(t_p) {0, 7});
	w->anim[WAIT] = ft_animation_set(0, 1, 150);
	w->anim[SHOOT] = ft_animation_set(0, 7, 150);
	w->anim[RELOAD] = ft_animation_set(0, 1, 150);
}

void	ft_weapon_load_shotgun(SDL_Renderer *r, t_game *g)
{
	t_weap	*w;

	g->weap[SHOTGUN] = ft_weapon_sprites_load(r, 39, "4_Shotgun");
	w = g->weap[SHOTGUN];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.65, 0.85}, WEAPON_DEF_SCALE,
	(t_p) {0, 5});
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.4, 1}, 4, (t_p) {5, 39});
	g->weap[SHOTGUN]->anim[WAIT] = ft_animation_set(0, 1, 100);
	g->weap[SHOTGUN]->anim[SHOOT] = ft_animation_set(0, 5, 120);
	g->weap[SHOTGUN]->anim[RELOAD] = ft_animation_set(5, 39, 80);
}

void	ft_weapon_load_static_rifle(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[STATIC_RIFLE] = ft_weapon_sprites_load(r, 4, "5_Static_Rifle");
	w = g->weap[STATIC_RIFLE];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.84, 0.82}, WEAPON_DEF_SCALE,
	(t_p) {0, 4});
	w->anim[WAIT] = ft_animation_set(0, 1, 150);
	w->anim[SHOOT] = ft_animation_set(0, 4, 100);
	w->anim[RELOAD] = ft_animation_set(0, 1, 150);
}
