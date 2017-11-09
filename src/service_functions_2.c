/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:42:05 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:42:06 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_game_player_reload(t_wnd *w, t_game *g)
{
	free(g->pl);
	g->pl = ft_game_player_create(w);
}

void	ft_game_free_maps_and_lvls(t_game *g)
{
	int	i;

	i = 0;
	while (i < LVL_NUM)
	{
		if (g->lvl[i].map.m != NULL)
			ft_free_2d_array((void **)g->lvl[i].map.m);
		i++;
	}
	free(g->lvl);
}

void	ft_game_lvl_reload(t_game *g)
{
	ft_game_free_maps_and_lvls(g);
	if ((g->lvl = malloc(sizeof(t_lvl) * LVL_NUM)) == NULL)
		ft_errors_general(ERR_MALLOC);
	ft_game_general_prm(g);
	ft_weapon_set_all_ammo_and_damage(g);
}

int		ft_map_get_cond_val(t_p p, t_map *map)
{
	t_tile	*tile;

	tile = ft_map_get_tile(map, p.x, p.y);
	if (tile->val == T12_LAVA || tile->val == T20_RAD_ORE
		|| tile->val == T63_BIOHAZ || tile->val == T69_DR_CHEM_WASTE)
		return (tile->val);
	return (0);
}
