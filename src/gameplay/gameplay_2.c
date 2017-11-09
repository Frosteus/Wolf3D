/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:05:40 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:05:42 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_regen_hp_and_stamina(t_pl *pl, double dt)
{
	ft_stat_mod(&pl->hp.st, &pl->hp.reg, dt);
	ft_stat_mod(&pl->st.st, &pl->st.reg, dt);
}

t_targ	ft_target_set(t_tgtp type, int pos_x, int pos_y)
{
	t_targ	targ;

	targ.t = type;
	targ.x[type] = pos_x;
	targ.y[type] = pos_y;
	return (targ);
}

int		ft_player_around_map_check_2(t_p *p, t_map *map)
{
	int	tlv;

	if (p->x < map->w && p->y < map->h
		&& (tlv = ft_map_get_cond_val(*p, map)) != 0)
		return (tlv);
	p->x--;
	if (p->y < map->h && (tlv = ft_map_get_cond_val(*p, map)) != 0)
		return (tlv);
	p->x--;
	if (p->x > 0 && p->y < map->h && (tlv = ft_map_get_cond_val(*p, map)) != 0)
		return (tlv);
	p->y--;
	if (p->x > 0 && (tlv = ft_map_get_cond_val(*p, map)) != 0)
		return (tlv);
	return (0);
}

int		ft_player_around_map_check(t_p p, t_map *map)
{
	int	tlv;

	p.x = p.x - 1;
	p.y = p.y - 1;
	if (p.x > 0 && p.y > 0 && (tlv = ft_map_get_cond_val(p, map)) != 0)
		return (tlv);
	p.x++;
	if (p.y > 0 && (tlv = ft_map_get_cond_val(p, map)) != 0)
		return (tlv);
	p.x++;
	if (p.x < map->w && p.y > 0 && (tlv = ft_map_get_cond_val(p, map)) != 0)
		return (tlv);
	p.y++;
	if (p.x < map->w && (tlv = ft_map_get_cond_val(p, map)) != 0)
		return (tlv);
	p.y++;
	return (ft_player_around_map_check_2(&p, map));
}

void	ft_block_player_damage(t_wnd *w, t_game *g, t_pl *pl, t_map *map)
{
	t_p		p;
	int		val;
	int		dmg;

	dmg = 0;
	p.x = (int)pl->pos.x;
	p.y = (int)pl->pos.y;
	if ((val = ft_player_around_map_check(p, map)) != 0)
	{
		if (val == T12_LAVA)
			dmg = 5;
		else if (val == T20_RAD_ORE)
			dmg = 1;
		else if (val == T63_BIOHAZ || val == T69_DR_CHEM_WASTE)
			dmg = 2;
		ft_sdl_sprite_wnd_box(w, g->buff.add[AS_BIOHAZ], NULL, SPR_WND_REL);
		pl->hp.deg.val = dmg;
		ft_stat_mod(&pl->hp.st, &pl->hp.deg, g->tm.del_t);
		pl->hp.deg.val = 1;
	}
}
