/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:03:15 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:03:16 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_gameplay_place_tile(t_pl *pl, t_map *map, t_tbuff *b)
{
	int		map_x;
	int		map_y;
	t_tile	*tile;

	map_x = (int)(pl->pos.x + F_WALL_BL + F_PUT_BL_DIST * pl->dir.x);
	map_y = (int)(pl->pos.y + F_WALL_BL + F_PUT_BL_DIST * pl->dir.y);
	tile = ft_map_get_tile(map, map_x, map_y);
	if (tile->val == 0)
	{
		tile->val = rand() % (b->mt_num + 1 - 3) + 3;
		tile->side[SIDE_LIGHT] = b->mtn[tile->val];
		tile->side[SIDE_DARK] = b->mtd[tile->val];
		tile->hp.st = ft_stat_set(1000, 0, 1000);
		tile->hp.deg = ft_stat_mod_set(1, STAT_SUB, 0);
	}
}

void	ft_map_set_tile_hp(t_tile *t)
{
	if (t->val == T1_BEDROCK || t->val == T2_SOULSAND || t->val == T0_EMPTY)
	{
		t->hp.st = ft_stat_set(0, 0, 0);
		t->hp.deg = ft_stat_mod_set(0, STAT_SUB, 0);
	}
	else
	{
		t->hp.st = ft_stat_set(1000, 0, 1000);
		t->hp.deg = ft_stat_mod_set(1, STAT_SUB, 0);
	}
}

void	ft_gameplay_block_destr_tex(t_tile *t, t_tbuff *b)
{
	if (t->hp.st.val > 0 && t->hp.st.val < t->hp.st.max)
		t->eff = b->dt[(int)((DESTR_TEX - 1)
		* (1 - t->hp.st.val / t->hp.st.max))];
	else if (t->val > T2_SOULSAND && t->hp.st.val == 0)
	{
		t->val = 0;
		t->side[SIDE_LIGHT] = NULL;
		t->side[SIDE_DARK] = NULL;
		t->eff = NULL;
		ft_map_set_tile_hp(t);
	}
}

void	ft_gameplay_block_shoot(t_pl *pl, t_weap *w, t_map *map, t_tbuff *b)
{
	t_tile	*t;
	t_targ	*targ;
	t_smod	mod;

	targ = &pl->targ;
	if (targ->t == TARG_TILE)
	{
		t = ft_map_get_tile(map, targ->x[TARG_TILE], targ->y[TARG_TILE]);
		mod = t->hp.deg;
		mod.val *= w->dmg;
		ft_stat_mod(&t->hp.st, &mod, 0);
		ft_gameplay_block_destr_tex(t, b);
	}
}
