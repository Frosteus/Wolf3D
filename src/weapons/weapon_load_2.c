/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_load_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:09:59 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 20:10:01 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_weapon_load_bfg9000(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[BFG9000] = ft_weapon_sprites_load(r, 27, "6_BFG9000");
	w = g->weap[BFG9000];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.6, 0.9}, WEAPON_DEF_SCALE,
	(t_p) {0, 19});
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.6, 0.9}, WEAPON_DEF_SCALE,
	(t_p) {19, 27});
	w->anim[WAIT] = ft_animation_set(0, 3, 150);
	w->anim[SHOOT] = ft_animation_set(0, 19, 80);
	w->anim[RELOAD] = ft_animation_set(19, 27, 80);
}

void	ft_weapon_load_rocket_launcher(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[ROCKET_LNCH] = ft_weapon_sprites_load(r, 27, "7_Rocket_Launcher");
	w = g->weap[ROCKET_LNCH];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.9, 0.81}, WEAPON_DEF_SCALE,
	(t_p) {0, 27});
	w->anim[WAIT] = ft_animation_set(0, 1, 100);
	w->anim[SHOOT] = ft_animation_set(1, 27, 120);
	w->anim[RELOAD] = ft_animation_set(1, 21, 70);
}

void	ft_weapon_load_gauss_gun(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[GAUSS_GUN] = ft_weapon_sprites_load(r, 17, "8_Gauss_Gun");
	w = g->weap[GAUSS_GUN];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.6, 0.84},
	WEAPON_DEF_SCALE - 0.2, (t_p) {0, 17});
	w->anim[WAIT] = ft_animation_set(0, 7, 200);
	w->anim[SHOOT] = ft_animation_set(7, 17, 150);
	w->anim[RELOAD] = ft_animation_set(0, 7, 200);
}

void	ft_weapon_load_heavy_assault_rifle(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[ASSAULT_RIFLE] = ft_weapon_sprites_load(r, 28, "9_Assault_Rifle");
	w = g->weap[ASSAULT_RIFLE];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.83, 0.83}, WEAPON_DEF_SCALE,
	(t_p) {0, 28});
	w->anim[WAIT] = ft_animation_set(0, 1, 50);
	w->anim[SHOOT] = ft_animation_set(1, 28, 70);
	w->anim[RELOAD] = ft_animation_set(0, 1, 50);
}

void	ft_weapon_load_lightning_gun(SDL_Renderer *r, t_game *g)
{
	t_weap *w;

	g->weap[LGTN_GUN] = ft_weapon_sprites_load(r, 11, "10_Lightning_gun");
	w = g->weap[LGTN_GUN];
	ft_weapon_buffer_pos_and_scale(w, (t_v2d) {0.8, 0.83}, WEAPON_DEF_SCALE,
	(t_p) {0, 11});
	w->anim[WAIT] = ft_animation_set(0, 2, 100);
	w->anim[SHOOT] = ft_animation_set(1, 11, 80);
	w->anim[RELOAD] = ft_animation_set(0, 2, 50);
}
