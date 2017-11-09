/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:45:31 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:45:32 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_trig	ft_trigger_set(int x, int y, int tl_val, t_trg type)
{
	t_trig trig;

	trig.map_pos.x = x;
	trig.map_pos.y = y;
	trig.tl_val = tl_val;
	trig.type = type;
	return (trig);
}

void	ft_trigger_set_to_default(t_trig *triggers, int num, t_trg type)
{
	int	i;

	i = 0;
	while (i < num)
	{
		triggers[i] = ft_trigger_set(0, 0, 0, type);
		i++;
	}
}
