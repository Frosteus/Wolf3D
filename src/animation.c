/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:48:50 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 19:48:52 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_anim	ft_animation_set(int f_st, int f_end, int f_delay)
{
	t_anim	a;

	a.f_st = f_st;
	a.f_end = f_end;
	a.tot_frames = a.f_end - f_st;
	a.f_delay = f_delay;
	a.tot_time = f_delay * (f_end - f_st);
	return (a);
}

void	ft_animation_set_total_anim_time(t_anim *a, int total_time)
{
	a->tot_time = total_time;
	a->f_delay = total_time / a->tot_frames;
}
