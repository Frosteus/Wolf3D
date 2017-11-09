/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog2_lvl1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:01:59 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:02:00 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_dial	ft_lvl1_dialog2_replica_1(t_tbuff *b)
{
	t_dial	d;

	d.name = "General Zodd";
	d.txt = "You made it. I understand. You think its paradise here. She "
		"protects you, but not long. Come and get what you deserve!";
	d.port = b->add[AS_GENERAL];
	return (d);
}

t_dial	ft_lvl1_dialog2_replica_2(t_tbuff *b)
{
	t_dial	d;

	d.name = "Demoness";
	d.txt = "Shut up, watchog! He's mine and only mine.";
	d.port = b->add[AS_SUCCUB];
	return (d);
}

t_dial	ft_lvl1_dialog2_replica_3(t_tbuff *b)
{
	t_dial	d;

	d.name = "General Zodd";
	d.txt = "You'll regret this partnership! Get them!";
	d.port = b->add[AS_GENERAL];
	return (d);
}

t_dial	ft_lvl1_dialog2_replica_4(t_tbuff *b)
{
	t_dial	d;

	d.name = "Demoness";
	d.txt = "We must take a tactical run away for now.";
	d.port = b->add[AS_SUCCUB];
	return (d);
}
