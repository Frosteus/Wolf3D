/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:23:50 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:23:51 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tile	**ft_create2d_tile_array(size_t col, size_t row)
{
	t_tile	**arr;
	size_t	i;

	i = 1;
	if ((arr = malloc(sizeof(t_tile *) * row)) == NULL)
		ft_errors_general(ERR_MALLOC);
	if ((arr[0] = malloc(sizeof(t_tile) * row * col)) == NULL)
		ft_errors_general(ERR_MALLOC);
	ft_memset(arr[0], '\0', sizeof(t_tile) * row * col);
	while (i != row)
	{
		arr[i] = arr[i - 1] + col;
		i++;
	}
	return (arr);
}

void	ft_map_bedrock_filling(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			map->m[i][j].val = T1_BEDROCK;
			j++;
		}
		i++;
	}
}

void	ft_map_add_texture(t_tbuff *b, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			map->m[i][j].side[SIDE_LIGHT] = b->mtn[map->m[i][j].val];
			map->m[i][j].side[SIDE_DARK] = b->mtd[map->m[i][j].val];
			ft_map_set_tile_hp(&map->m[i][j]);
			map->m[i][j].eff = NULL;
			j++;
		}
		i++;
	}
}

void	ft_map_parse(t_tbuff *b, t_lvl *lvl, t_pl *pl)
{
	int		fd;
	t_map	*map;

	map = &lvl->map;
	fd = ft_get_file_fd(lvl->map_name);
	ft_map_parse_position_and_start(lvl, pl, fd);
	lvl->map.m = ft_create2d_tile_array((size_t)map->w, (size_t)map->h);
	ft_map_bedrock_filling(map);
	ft_map_filling(map, fd);
	ft_map_add_texture(b, map);
	map->m[(int)pl->pos.x][(int)pl->pos.y].val = 0;
	close(fd);
}
