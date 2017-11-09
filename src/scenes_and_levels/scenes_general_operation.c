/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_general_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:25:11 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:25:12 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sc	ft_scene_menu_general_op(t_sc c_sc, t_lprm *lprm, t_menu *menu)
{
	t_btn	*b;

	b = ft_menu_btn_selection(menu, lprm->ms_coord);
	ft_sdl_panel_show_all_btn(menu->p);
	ft_menu_btn_deselection(b);
	ft_menu_controls(&c_sc, lprm, menu);
	return (c_sc);
}

void	ft_scene_show_blood_splat(t_spr *blood, t_pl *pl)
{
	SDL_SetTextureAlphaMod(blood->tex->t,
	(Uint8)(255 * (pl->hp.st.max - pl->hp.st.val) / 100));
	ft_sdl_sprite_show(blood, NULL, SPR_SPR_TO_SCR);
}

t_sc	ft_scene_reload(t_sc c_sc, t_lprm *lprm, t_game *g)
{
	ft_sdl_sprite_show(g->buff.add[AS_LOAD], NULL, SPR_SPR_TO_SCR);
	ft_game_restart(lprm->wnd, g);
	c_sc = SC_GAME;
	return (c_sc);
}
