/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:51:39 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:51:40 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_lprm	*ft_init_loop_sdl_prm(void)
{
	t_lprm	*lprm;

	if ((lprm = malloc(sizeof(t_lprm))) == NULL)
		ft_errors_general(ERR_MALLOC);
	if ((lprm->wnd = malloc(sizeof(t_wnd))) == NULL)
		ft_errors_general(ERR_MALLOC);
	ft_sdl_set_wnd_prm(lprm->wnd, S_WID, S_HEI, WND_NAME);
	ft_sdl_create_window_and_renderer(lprm->wnd);
	SDL_GetWindowSize(lprm->wnd->p, &lprm->base_sc.x, &lprm->base_sc.y);
	lprm->ms_coord.x = 0;
	lprm->ms_coord.y = 0;
	SDL_PollEvent(&lprm->e);
	lprm->efl = false;
	return (lprm);
}

void	ft_init_application_prm(t_id *id)
{
	id->loop = true;
	id->lprm = ft_init_loop_sdl_prm();
	ft_sdl_set_window_title(id->lprm->wnd);
	ft_sdl_set_window_minimum(id->lprm->wnd, 640, 480);
	ft_scene_set(id);
}
