/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:31:11 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:31:15 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_dialog_box_show(t_wnd *w, t_game *g, t_dial *d)
{
	t_drect	dr;

	dr = ft_sdl_rect_spr_dest_rel(g->buff.add[AS_DIAL], g->d.pos[0]);
	ft_sdl_sprite_wnd_box(w, d->port, &dr, SPR_CALC_WND_REL);
	ft_sdl_sprite_wnd_box(w, g->buff.add[AS_DIAL], NULL, SPR_WND_REL);
	dr = ft_sdl_rect_spr_dest_rel(g->buff.add[AS_DIAL], g->d.pos[1]);
	ft_font_txtbox(g->gfont, ft_sdl_rect_wndrel(w, dr), d->name, 0.25);
	dr = ft_sdl_rect_spr_dest_rel(g->buff.add[AS_DIAL], g->d.pos[2]);
	ft_font_txtbox(g->gfont, ft_sdl_rect_wndrel(w, dr), d->txt, 0.2);
}

void	ft_dialog_box_skip(t_lprm *lprm, t_game *g, t_lvl *lvl)
{
	if (lprm->efl == true && lprm->e.type == SDL_KEYDOWN)
		if (lvl->c_lvlp == LVL_DIAL_EV || lvl->c_lvlp == LVL_EDIAL_EV)
			if (lprm->e.key.keysym.sym == SDLK_SPACE)
				g->d.d_flag += 1;
}
