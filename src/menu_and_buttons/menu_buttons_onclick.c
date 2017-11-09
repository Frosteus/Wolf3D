/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_buttons_onclick.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:29:30 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:29:31 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sc	ft_resume_click(void)
{
	return (SC_GAME);
}

t_sc	ft_new_game_click(void)
{
	return (SC_RELOAD);
}

t_sc	ft_options_click(void)
{
	return (SC_OPTIONS);
}

t_sc	ft_exit_click(void)
{
	return (SC_EXIT);
}
