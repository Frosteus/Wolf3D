/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:24:54 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 20:24:55 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_weapon_action(t_lprm *lprm, t_game *g)
{
	int		ind;
	t_anim	*a;
	t_weap	*w;
	char	num[20];

	w = g->weap[g->sel_w];
	a = &w->anim[w->w_st];
	ind = a->f_st;
	w->timer += g->tm.del_t;
	w->fr_cntr++;
	ind += ((int)(w->timer) / a->f_delay) % a->tot_frames;
	if (w->timer >= a->tot_time)
	{
		if (w->w_st == SHOOT && w->ammo > 0)
		{
			ft_gameplay_block_shoot(g->pl, w, &g->lvl[g->c_lvl].map, &g->buff);
			w->ammo--;
		}
		w->w_st = WAIT;
		w->timer = 0;
		w->fr_cntr = 0;
	}
	ft_sdl_spr2_to_point(lprm->wnd, w->spr[ind], w->spr[ind]->dst, lprm->xy_sc);
	ft_font_txtbox(g->gfont, ft_sdl_rect_wndrel(lprm->wnd, DRSET(90, 90,
	10, 5)), ft_itoa_base(w->ammo, num, 10), 0.4 * lprm->xy_sc.x);
}

void	ft_weapon_unload_all_free_inventory(t_game *g)
{
	enum e_weap	weap;

	weap = (enum e_weap)0;
	while (weap < WEAPON_NUM)
	{
		ft_weapon_spritebuff_free(g->weap[weap]);
		weap++;
	}
	free(g->weap);
}

void	ft_weapon_set_all_ammo_and_damage(t_game *g)
{
	ft_weapon_set_dmg_and_ammo(g->weap[PISTOL], 25, 100);
	ft_weapon_set_dmg_and_ammo(g->weap[REPEATER], 25, 200);
	ft_weapon_set_dmg_and_ammo(g->weap[HELLSHOT], 200, 30);
	ft_weapon_set_dmg_and_ammo(g->weap[SHOTGUN], 300, 20);
	ft_weapon_set_dmg_and_ammo(g->weap[STATIC_RIFLE], 75, 80);
	ft_weapon_set_dmg_and_ammo(g->weap[BFG9000], 9000, 5);
	ft_weapon_set_dmg_and_ammo(g->weap[ROCKET_LNCH], 1000, 10);
	ft_weapon_set_dmg_and_ammo(g->weap[GAUSS_GUN], 250, 10);
	ft_weapon_set_dmg_and_ammo(g->weap[ASSAULT_RIFLE], 500, 30);
	ft_weapon_set_dmg_and_ammo(g->weap[LGTN_GUN], 200, 80);
	ft_weapon_set_dmg_and_ammo(g->weap[DOOMDOLL], 0, 999);
}

void	ft_weapon_create_inventory_load_all(SDL_Renderer *r, t_game *g)
{
	ft_weapon_create_inventory(g, WEAPON_NUM);
	ft_weapon_load_pistol(r, g);
	ft_weapon_load_repeater(r, g);
	ft_weapon_load_hellshot(r, g);
	ft_weapon_load_shotgun(r, g);
	ft_weapon_load_static_rifle(r, g);
	ft_weapon_load_bfg9000(r, g);
	ft_weapon_load_rocket_launcher(r, g);
	ft_weapon_load_gauss_gun(r, g);
	ft_weapon_load_heavy_assault_rifle(r, g);
	ft_weapon_load_lightning_gun(r, g);
	ft_weapon_load_doomdoll(r, g);
	ft_weapon_set_all_ammo_and_damage(g);
}
