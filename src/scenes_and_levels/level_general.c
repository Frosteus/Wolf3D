/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:52:26 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:52:27 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_lvl1(t_lvl *lvl)
{
	lvl->part[LVL_START].fun = ft_lvl1_setting_up;
	lvl->part[LVL_DIAL_EV].fun = ft_lvl1_dial_event;
	lvl->part[LVL_PLAY].fun = ft_lvl1_gameplay;
	lvl->part[LVL_EDIAL_EV].fun = ft_lvl1_dial_event_2;
	lvl->part[LVL_END].fun = ft_lvl_end;
	lvl->name = LVL_1_NAME;
	lvl->map_name = PATH_MAP_LEVEL1;
	lvl->map.m = NULL;
	lvl->win_trig.tl_val = false;
}

void	ft_init_lvl2(t_lvl *lvl)
{
	lvl->part[LVL_START].fun = ft_lvl2_setting_up;
	lvl->part[LVL_DIAL_EV].fun = ft_lvl2_dial_event;
	lvl->part[LVL_PLAY].fun = ft_lvl2_gameplay;
	lvl->part[LVL_EDIAL_EV].fun = NULL;
	lvl->part[LVL_END].fun = ft_lvl_end;
	lvl->name = LVL_2_NAME;
	lvl->map_name = PATH_MAP_LEVEL2;
	lvl->map.m = NULL;
	lvl->win_trig.tl_val = false;
}

void	ft_init_lvl3(t_lvl *lvl)
{
	lvl->part[LVL_START].fun = ft_lvl3_setting_up;
	lvl->part[LVL_DIAL_EV].fun = NULL;
	lvl->part[LVL_PLAY].fun = ft_lvl3_gameplay;
	lvl->part[LVL_EDIAL_EV].fun = NULL;
	lvl->part[LVL_END].fun = ft_lvl_end;
	lvl->name = LVL_3_NAME;
	lvl->map_name = PATH_MAP_LEVEL3;
	lvl->map.m = NULL;
	lvl->win_trig.tl_val = false;
}

void	ft_level_part_lvl_num_change(t_game *g)
{
	t_lvl	*lvl;

	lvl = &g->lvl[g->c_lvl];
	if (lvl->win_trig.bool == true)
	{
		if (lvl->c_lvlp + 1 != LVL_END
			&& lvl->part[lvl->c_lvlp + 1].fun != NULL)
			lvl->c_lvlp = lvl->c_lvlp + 1;
		else if (g->c_lvl < LVL_NUM)
			g->c_lvl = g->c_lvl + 1;
	}
}

void	ft_lvl_end(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	ft_game_loop_regular_operation(lprm, g, lvl);
	if (g->buff.alpha < 255)
	{
		ft_sdl_sprite_show(g->buff.add[AS_FADE], NULL, SPR_SPR_TO_SCR);
		SDL_SetTextureAlphaMod(g->buff.add[AS_FADE]->tex->t, g->buff.alpha);
		SDL_Delay(10);
		g->buff.alpha++;
	}
	else
	{
		if (g->c_lvl != LEVEL3)
			g->c_lvl++;
		else
			g->lvl[LEVEL3].win_trig.bool = true;
	}
}
