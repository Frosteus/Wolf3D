/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:51:14 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:51:16 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_weapon_set_dmg_and_ammo(t_weap *w, int dmg, int ammo)
{
	w->dmg = dmg;
	w->ammo = ammo;
}

void	ft_weapon_buffer_pos_and_scale(t_weap *w, t_v2d pos, double sc, t_p ft)
{
	int	i;

	i = ft.x;
	while (i < ft.y)
	{
		w->spr[i]->dst = pos;
		w->spr[i]->sx = sc;
		w->spr[i]->sy = sc;
		i++;
	}
}

void	ft_weapon_create_inventory(t_game *g, int weap_num)
{
	if ((g->weap = malloc(sizeof(t_weap *) * weap_num)) == NULL)
		ft_errors_general(ERR_MALLOC);
}

t_weap	*ft_weapon_sprites_load(SDL_Renderer *re, int fr, char *fn)
{
	t_weap	*w;
	int		i;
	char	*full_path;

	if ((w = malloc(sizeof(t_weap))) == NULL)
		ft_errors_general(ERR_MALLOC);
	if ((w->spr = malloc(sizeof(t_spr_p *) * fr)) == NULL)
		ft_errors_general(ERR_MALLOC);
	w->fr = fr;
	i = 0;
	while (i < w->fr)
	{
		full_path = ft_path_catstr(WEAPON_PATH, fn, i, 1);
		w->spr[i] = ft_sdl_sprite2_create_from_file(re, full_path);
		free(full_path);
		i++;
	}
	w->timer = 0;
	w->fr_cntr = 0;
	w->w_st = WAIT;
	return (w);
}

void	ft_weapon_spritebuff_free(t_weap *w)
{
	int	i;

	i = 0;
	while (i < w->fr)
	{
		ft_sdl_sprite2_and_texture_free(w->spr[i]);
		i++;
	}
	free(w->spr);
	free(w);
}
