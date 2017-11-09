/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:39:19 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:41:14 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_font_dim_parse(int fd, SDL_Rect *r)
{
	char	**rect;
	char	**ptr;
	char	*str;

	if (ft_get_line(fd, &str) < 0)
		ft_errors_general(ERR_GET_LINE);
	rect = ft_strsplit(str, ',');
	ptr = rect;
	r->x = ft_atoi(ptr[0]);
	r->y = ft_atoi(ptr[1]);
	r->w = ft_atoi(ptr[2]);
	r->h = ft_atoi(ptr[3]);
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	free(rect);
	free(str);
}

t_sprbf	*ft_font_rect_parse(int sz, int fd, t_tex *t)
{
	t_sprbf		*fbuf;
	SDL_Rect	*f_arr;
	int			i;

	if ((f_arr = malloc(sizeof(SDL_Rect) * sz)) == NULL)
		ft_errors_general(ERR_MALLOC);
	i = 0;
	while (i < sz)
	{
		ft_font_dim_parse(fd, &f_arr[i]);
		i++;
	}
	fbuf = ft_sdl_spr_buffer_create(t, f_arr, sz);
	free(f_arr);
	return (fbuf);
}

t_sprbf	*ft_font_parse(SDL_Renderer *r)
{
	t_sprbf		*fbuf;
	t_tex		*t;
	char		*str;
	int			sz;
	int			fd;

	fd = ft_get_file_fd(PATH_GAME_FONT_RECT);
	if (ft_get_line(fd, &str) < 0)
		ft_errors_general(ERR_GET_LINE);
	if ((sz = ft_atoi(str)) == 0)
		ft_errors_custom("Error in font rect file.\n");
	free(str);
	t = ft_sdl_texture_from_image_heap(r, PATH_GAME_FONT);
	fbuf = ft_font_rect_parse(sz, fd, t);
	close(fd);
	return (fbuf);
}

void	ft_font_txtbox(t_sprbf *gf, SDL_Rect box, const char *txt, double sc)
{
	SDL_Rect	dest;
	int			index;
	t_spr		*spr;
	t_p			tp;

	tp = (t_p){0, 0};
	while (*txt != '\0')
	{
		index = *txt - (*txt >= 'a' && *txt <= 'z' ? 64 : 32);
		if (index >= 0 && index < gf->sz)
		{
			spr = gf->s_arr[index];
			if (tp.x + (int)(spr->src.w * sc) > box.w)
			{
				tp.x = 0;
				tp.y += (int)(100 * sc);
			}
			dest = ft_sdl_rect_set(box.x + tp.x, box.y + tp.y,
			(int)(spr->src.w * sc), (int)(spr->src.h * sc));
			ft_sdl_sprite_show(spr, &dest, SPR_NORMAL);
			tp.x += (int)(spr->src.w * sc);
		}
		txt++;
	}
}
