/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog1_lvl2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:52:00 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 14:52:01 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_dial	ft_lvl2_dialog_replica_1(t_tbuff *b)
{
	t_dial	d;

	d.name = "Black Queen";
	d.txt = "So, Hookbill, your frogs did well! But let us see how they do agai"
		"nst my birds of prey - Pray the birds don't get them! Ha-ha-ha-ha!";
	d.port = b->add[AS_QUEEN];
	return (d);
}

t_dial	ft_lvl2_dialog_replica_2(t_tbuff *b)
{
	t_dial	d;

	d.name = "Black Queen";
	d.txt = "You managed to avoid my traps, eh! Well, it takes a booby to beat "
		"a booby, I always say!";
	d.port = b->add[AS_QUEEN];
	return (d);
}
