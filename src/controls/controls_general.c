/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:51:06 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 19:51:07 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_general_keydown_check(t_id *id, t_sc *c_sc)
{
	SDL_Event *e;

	e = &id->lprm->e;
	if (id->lprm->efl == false)
		return ;
	if (e->type == SDL_QUIT)
		id->loop = false;
	else if (e->type == SDL_KEYDOWN)
	{
		if (e->key.keysym.sym == SDLK_ESCAPE)
		{
			if (*c_sc == SC_MENU || *c_sc == SC_GAME_PAUSE)
				id->loop = false;
			else if (*c_sc == SC_GAME)
				*c_sc = SC_GAME_PAUSE;
		}
	}
}
