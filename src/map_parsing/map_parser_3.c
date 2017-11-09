/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:26:02 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 15:26:03 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_map_get_offset(int *off, char *str)
{
	size_t	st;
	size_t	len;
	char	*pos;

	len = ft_strlen(str);
	if ((pos = ft_memchr(str, '/', len)) == NULL)
	{
		ft_map_parse_errors(MAP_NO_OFFSET_LEFT);
		st = 0;
	}
	else
	{
		st = pos - str;
		*off = ft_atoi(str);
		if (st > 0)
			st++;
	}
	return (str + st);
}

void	ft_free_split_char_arr(char **split)
{
	char	**ptr;

	ptr = split;
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	free(split);
}

void	ft_map_parse_line(t_map *map, char *str, int i)
{
	char	**split;
	char	**ptr;
	char	*st;
	int		off;
	int		j;

	off = 0;
	st = ft_map_get_offset(&off, str);
	if (off > map->w)
		ft_map_parse_errors(MAP_EXCESS_OFFSET);
	j = off + 1;
	if ((split = ft_strsplit(st, ' ')) == NULL)
		ft_errors_general(ERR_MALLOC);
	ptr = split;
	while (j < map->w - 1 && *ptr != NULL)
	{
		ft_map_parse_num_lim(*ptr, &map->m[i][j].val, 0, MAP_TEX - 1);
		ptr++;
		j++;
	}
	ft_free_split_char_arr(split);
}

void	ft_map_filling(t_map *map, int fd)
{
	char	*str;
	int		i;

	i = 1;
	while (i < map->h - 1)
	{
		if (ft_get_line(fd, &str) < 0 && ft_strlen(str) > 0)
			ft_errors_general(ERR_GET_LINE);
		ft_map_parse_line(map, str, i);
		free(str);
		i++;
	}
}
