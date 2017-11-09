/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:25:34 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:25:35 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_map_parse_errors(int err)
{
	if (err == MAP_DATA_ERR)
		ft_errors_custom("Wrong map data\n");
	else if (err == MAP_LIMITS_ERR)
		ft_errors_custom("Data is out of map limits!\n");
	else if (err == MAP_LOW_DATA)
		ft_errors_custom("You have low height data!\n");
	if (err == MAP_EXCESS_DATA)
		ft_errors_warning("You have excess height data!\n");
	else if (err == MAP_NO_OFFSET_LEFT)
		ft_errors_warning("No left margin offset info!\n");
	else if (err == MAP_EXCESS_OFFSET)
		ft_errors_warning("Left offset is excess map width!\n");
	else
		exit(0);
}

void	ft_map_parse_num_lim(char *str, int *num, int lmin, int lmax)
{
	if (ft_strlen(str) == 0)
		ft_map_parse_errors(MAP_DATA_ERR);
	*num = ft_atoi(str);
	if (*num < lmin || *num > lmax)
		ft_map_parse_errors(MAP_LIMITS_ERR);
}

void	ft_map_parse_position_and_start(t_lvl *lvl, t_pl *pl, int fd)
{
	char	*str;
	int		num;

	if (ft_get_line(fd, &str) < 0)
		ft_errors_general(ERR_GET_LINE);
	ft_map_parse_num_lim(str, &lvl->map.h, MAP_MIN, MAP_MAX);
	free(str);
	if (ft_get_line(fd, &str) < 0)
		ft_errors_general(ERR_GET_LINE);
	ft_map_parse_num_lim(str, &lvl->map.w, MAP_MIN, MAP_MAX);
	free(str);
	if (ft_get_line(fd, &str) < 0)
		ft_errors_general(ERR_GET_LINE);
	ft_map_parse_num_lim(str, &num, 0, lvl->map.w - 1);
	pl->pos.x = num + MAP_PLAYER_OFF;
	free(str);
	if (ft_get_line(fd, &str) < 0)
		ft_errors_general(ERR_GET_LINE);
	ft_map_parse_num_lim(str, &num, 0, lvl->map.h - 1);
	pl->pos.y = num + MAP_PLAYER_OFF;
	free(str);
	lvl->map.h += MAP_PROTECTION;
	lvl->map.w += MAP_PROTECTION;
}
