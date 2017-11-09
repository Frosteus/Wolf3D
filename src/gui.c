/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:39:08 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:39:11 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_gui_set(t_wnd *w, t_gui *gui)
{
	if ((gui->bs = malloc(sizeof(t_spr *) * GUI_ELEM_NUM)) == NULL)
		ft_errors_general(ERR_MALLOC);
	gui->bs[GUI_CROSS] = ft_sdl_sprite_create_from_file(w->r, GUI_CROSS_PATH);
	gui->bs[GUI_CROSS]->dest = ft_sdl_rect_set(48, 47, 4, 6);
	gui->bs[GUI_HBAR] = ft_sdl_sprite_create_from_file(w->r, GUI_BAR_PATH);
	gui->bs[GUI_HBAR]->dest = ft_sdl_rect_set(8, 89, 16, 4);
	gui->bs[GUI_HP_BAR] = ft_sdl_sprite_create_from_file(w->r, GUI_HP_PATH);
	gui->bs[GUI_HP_BAR]->dest = ft_sdl_rect_set(8, 89, 16, 4);
	gui->bs[GUI_SBAR] = ft_sdl_sprite_create_from_file(w->r, GUI_BAR_PATH);
	gui->bs[GUI_SBAR]->dest = ft_sdl_rect_set(8, 94, 16, 4);
	gui->bs[GUI_ST_BAR] = ft_sdl_sprite_create_from_file(w->r, GUI_ST_PATH);
	gui->bs[GUI_ST_BAR]->dest = ft_sdl_rect_set(8, 94, 16, 4);
	gui->bs[GUI_HEART] = ft_sdl_sprite_create_from_file(w->r, GUI_HEART_PATH);
	gui->bs[GUI_HEART]->dest = ft_sdl_rect_set(1, 88, 6, 8);
}

void	ft_gui_show(t_wnd *w, t_gui *gui, t_pl *pl)
{
	t_drect	dr;

	ft_sdl_sprite_wnd_box(w, gui->bs[GUI_CROSS], NULL, SPR_WND_REL);
	dr = ft_sdl_rect_int_to_d(gui->bs[GUI_HP_BAR]->dest);
	dr.w = dr.w * pl->hp.st.val / pl->hp.st.max;
	ft_sdl_sprite_wnd_box(w, gui->bs[GUI_HP_BAR], &dr, SPR_CALC_WND_REL);
	ft_sdl_sprite_wnd_box(w, gui->bs[GUI_HBAR], NULL, SPR_WND_REL);
	dr = ft_sdl_rect_int_to_d(gui->bs[GUI_ST_BAR]->dest);
	dr.w = dr.w * pl->st.st.val / pl->st.st.max;
	ft_sdl_sprite_wnd_box(w, gui->bs[GUI_ST_BAR], &dr, SPR_CALC_WND_REL);
	ft_sdl_sprite_wnd_box(w, gui->bs[GUI_SBAR], NULL, SPR_WND_REL);
	ft_sdl_sprite_wnd_box(w, gui->bs[GUI_HEART], NULL, SPR_WND_REL);
}
