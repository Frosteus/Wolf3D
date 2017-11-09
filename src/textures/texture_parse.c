/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:27:51 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 20:27:52 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_texbuff_set_constant_prm(t_tbuff *b)
{
	b->mt_num = MAP_TEX;
	b->mtn[0] = NULL;
	b->mtd[0] = NULL;
	b->mt_num = MAP_TEX;
}

void	ft_texture_parser(t_tbuff *b, SDL_Renderer *r)
{
	int		fd;
	char	*str;
	char	*path;
	int		i;

	fd = ft_get_file_fd(PATH_TEX_LIST);
	if ((b->mtn = malloc(sizeof(t_spr *) * (MAP_TEX + 1))) == NULL)
		ft_errors_general(ERR_MALLOC);
	if ((b->mtd = malloc(sizeof(t_spr *) * (MAP_TEX + 1))) == NULL)
		ft_errors_general(ERR_MALLOC);
	ft_texbuff_set_constant_prm(b);
	i = 1;
	while (i < b->mt_num + 1)
	{
		if (ft_get_line(fd, &str) < 0)
			ft_errors_general(ERR_GET_LINE);
		path = ft_strjoin(PATH_MAP_TEX, str);
		b->mtn[i] = ft_sdl_sprite_create_from_file(r, path);
		b->mtd[i] = ft_sdl_sprite_create_from_file(r, path);
		SDL_SetTextureColorMod(b->mtd[i]->tex->t, 150, 150, 150);
		free(path);
		free(str);
		i++;
	}
	close(fd);
}

void	ft_texture_destr_parser(t_tbuff *b, SDL_Renderer *r, int num)
{
	int		i;
	char	*path;

	if ((b->dt = malloc(sizeof(t_spr *) * (num))) == NULL)
		ft_errors_general(ERR_MALLOC);
	b->dt_num = num;
	i = 0;
	while (i < b->dt_num)
	{
		path = ft_path_catstr(PATH_MAP_TEX, DESTR_TEX_PREFIX, i, 0);
		b->dt[i] = ft_sdl_sprite_create_from_file(r, path);
		free(path);
		i++;
	}
}
