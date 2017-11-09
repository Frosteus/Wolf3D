/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:51:41 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 19:51:43 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_menu_controls(t_sc *c_sc, t_lprm *lprm, t_menu *menu)
{
	t_btn	*b;

	if (lprm->efl == false)
		return ;
	if (lprm->e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (lprm->e.button.button == SDL_BUTTON_LEFT)
		{
			if (*c_sc == SC_MENU || *c_sc == SC_GAME_PAUSE)
			{
				b = ft_sdl_panel_mouse_check(menu->p, lprm->ms_coord);
				if (b != NULL && b->flags & IS_ABLE)
					*c_sc = (t_sc)b->f_click();
			}
		}
	}
}
