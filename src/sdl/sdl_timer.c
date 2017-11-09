/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:07:49 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:07:53 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

t_timer	ft_sdl_timer_create(void)
{
	t_timer	t;

	t.all_t = SDL_GetTicks();
	t.pau_t = 0;
	t.cur_t = 0;
	t.del_t = 0;
	t.frm = 1;
	return (t);
}

void	ft_sdl_timer_calc_delta_and_frame(t_timer *t)
{
	t->all_t = t->cur_t;
	t->cur_t = SDL_GetTicks();
	t->del_t = t->cur_t - t->all_t;
	t->fra_t = 1. / (t->del_t / 1000.);
}

double	ft_sdl_timer_get_delta(t_timer *t)
{
	return (t->del_t);
}
