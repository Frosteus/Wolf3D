/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog_lvl1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:31:25 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 14:50:01 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_dial	ft_lvl1_dialog_replica_1(t_tbuff *b)
{
	t_dial	d;

	d.name = "Black Queen";
	d.txt = "Pitiful mere mortal, how you dare come to my world? You shall "
		"suffer for your insolence. Think you can overcome my defenses? Let's "
		"see how will you fulfill this task...";
	d.port = b->add[AS_QUEEN];
	return (d);
}

t_dial	ft_lvl1_dialog_replica_2(t_tbuff *b)
{
	t_dial	d;

	d.name = "Demoness";
	d.txt = "Do not be afraid, my master. These are empty threats. I'll "
		"help you destroy her and we will rule this world together.";
	d.port = b->add[AS_SUCCUB];
	return (d);
}

t_dial	ft_lvl1_dialog_replica_3(t_tbuff *b)
{
	t_dial	d;

	d.name = "Black Queen";
	d.txt = "How dare you, traitor! You don't even understand what"
		" you both are doing. Still it doesn't matter...";
	d.port = b->add[AS_QUEEN];
	return (d);
}

t_dial	ft_lvl1_dialog_replica_4(t_tbuff *b)
{
	t_dial	d;

	d.name = "General Zodd";
	d.txt = "I will hunt him down as he approaches, milady. Count on "
		"me. This wretched worm is doomed.";
	d.port = b->add[AS_GENERAL];
	return (d);
}

t_dial	ft_lvl1_dialog_replica_5(t_tbuff *b)
{
	t_dial	d;

	d.name = "Demoness";
	d.txt = "I know about a secret teleporter switch nearby, but this zone "
		"is filled with radioactive hazards. Find it. We had a long bloody "
		"way to get here, so don't mess up everything.";
	d.port = b->add[AS_SUCCUB];
	return (d);
}
