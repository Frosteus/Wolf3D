/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_game_weapon.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:22:38 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/24 15:22:40 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_game_controls_weapon(t_lprm *lprm, t_game *g)
{
	if (lprm->efl == false)
		return ;
	if (lprm->e.type == SDL_KEYDOWN)
	{
		if (lprm->e.key.keysym.sym == SDLK_r)
		{
			if (g->weap[g->sel_w]->w_st == WAIT && g->weap[g->sel_w]->ammo > 0)
				g->weap[g->sel_w]->w_st = RELOAD;
		}
		else
			ft_controls_game_weap_set(&lprm->e, g);
	}
}

void	ft_controls_game_weap_set(SDL_Event *e, t_game *g)
{
	if ((e->key.keysym.sym >= SDLK_0 && e->key.keysym.sym <= SDLK_9) ||
		e->key.keysym.sym == SDLK_EQUALS)
	{
		g->weap[g->sel_w]->timer = 0;
		g->weap[g->sel_w]->timer = WAIT;
		if (e->key.keysym.sym == SDLK_EQUALS)
			g->sel_w = DOOMDOLL;
		else
			g->sel_w = e->key.keysym.sym - SDLK_0;
	}
}
