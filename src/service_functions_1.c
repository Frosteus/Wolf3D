/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:37:07 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 20:38:09 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_path_catstr(char *r_path, char *name, int i, int off)
{
	char	*path;
	char	*num;
	size_t	len;

	if ((num = malloc(sizeof(char) * 20)) == NULL)
		ft_errors_general(ERR_MALLOC);
	num = ft_itoa_base(i + off, num, 10);
	len = ft_strlen(r_path) + ft_strlen(name) + ft_strlen("/")
	+ ft_strlen(num) + ft_strlen(EXT);
	path = ft_strnew(len);
	path = ft_strcat(path, r_path);
	path = ft_strcat(path, name);
	path = ft_strcat(path, DIVIDER);
	path = ft_strcat(path, num);
	path = ft_strcat(path, EXT);
	free(num);
	return (path);
}

t_v2d	ft_game_move_restr(t_v2d pos, t_v2d dir, double c_mvspd, int sign)
{
	t_v2d mvr;

	mvr.x = pos.x + sign * dir.x * c_mvspd;
	mvr.y = pos.y + sign * dir.y * c_mvspd;
	return (mvr);
}

int		ft_game_move_possible(t_tile **m, double r1, double r2, double wb)
{
	if (m[(int)(r1 + wb)][(int)(r2 + wb)].val == 0
		&& m[(int)(r1 - wb)][(int)(r2 - wb)].val == 0
		&& m[(int)(r1 + wb)][(int)(r2 - wb)].val == 0
		&& m[(int)(r1 - wb)][(int)(r2 + wb)].val == 0)
		return (1);
	return (0);
}

t_tile	*ft_map_get_tile(t_map *map, int map_x, int map_y)
{
	return (&map->m[map_x][map_y]);
}
