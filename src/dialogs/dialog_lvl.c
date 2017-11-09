/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog_lvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:03:12 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 16:03:13 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_lvl1_queen_dialog(t_wnd *w, t_game *g)
{
	t_dial		d;

	g->d.d_tm++;
	if (g->d.d_flag == 0)
		d = ft_lvl1_dialog_replica_1(&g->buff);
	if (g->d.d_flag == 1)
		d = ft_lvl1_dialog_replica_2(&g->buff);
	if (g->d.d_flag == 2)
		d = ft_lvl1_dialog_replica_3(&g->buff);
	if (g->d.d_flag == 3)
		d = ft_lvl1_dialog_replica_4(&g->buff);
	if (g->d.d_flag == 4)
		d = ft_lvl1_dialog_replica_5(&g->buff);
	if (g->d.d_flag < 5)
		ft_dialog_box_show(w, g, &d);
}

void	ft_lvl1_queen_dialog_2(t_wnd *w, t_game *g)
{
	t_dial	d;

	g->d.d_tm++;
	if (g->d.d_flag == 0)
		d = ft_lvl1_dialog2_replica_1(&g->buff);
	if (g->d.d_flag == 1)
		d = ft_lvl1_dialog2_replica_2(&g->buff);
	if (g->d.d_flag == 2)
		d = ft_lvl1_dialog2_replica_3(&g->buff);
	if (g->d.d_flag == 3)
		d = ft_lvl1_dialog2_replica_4(&g->buff);
	if (g->d.d_flag < 4)
		ft_dialog_box_show(w, g, &d);
}

void	ft_lvl2_queen_dialog_1(t_wnd *w, t_game *g)
{
	t_dial	d;

	g->d.d_tm++;
	if (g->d.d_flag == 0)
		d = ft_lvl2_dialog_replica_1(&g->buff);
	if (g->d.d_flag == 1)
		d = ft_lvl2_dialog_replica_2(&g->buff);
	if (g->d.d_flag < 2)
		ft_dialog_box_show(w, g, &d);
}
