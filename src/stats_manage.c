/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:43:34 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:43:35 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_cstat	ft_stat_set(int val, int min, int max)
{
	t_cstat	st;

	st.val = val;
	st.min = min;
	st.max = max;
	return (st);
}

t_smod	ft_stat_mod_set(int val, t_st_act act, double tt)
{
	t_smod mod;

	mod.val = val;
	mod.et = tt;
	mod.dt = 0;
	mod.act = act;
	return (mod);
}

int		ft_stat_check(t_cstat *st, double val, t_st_act act)
{
	if (act == STAT_MIN && val > st->min)
		return (1);
	else if (act == STAT_MAX && val < st->max)
		return (1);
	else if (act == STAT_VAL_LOW && st->val < val)
		return (1);
	else if (act == STAT_VAL_HIG && st->val > val)
		return (1);
	return (0);
}

void	ft_stat_action(t_cstat *st, double val, t_st_act act)
{
	if (act == STAT_SUB)
		st->val -= val;
	else if (act == STAT_ADD)
		st->val += val;
	else if (act == STAT_MULT)
		st->val *= val;
	else if (act == STAT_DIV)
	{
		if (val == 0)
			ft_errors_general(ERR_DIV_ZERO);
		st->val /= val;
	}
	if (st->val <= st->min)
		st->val = st->min;
	if (st->val >= st->max)
		st->val = st->max;
}

void	ft_stat_mod(t_cstat *st, t_smod *mod, double dt)
{
	mod->dt += dt;
	if (mod->dt >= mod->et)
	{
		ft_stat_action(st, mod->val, mod->act);
		mod->dt = 0;
	}
}
