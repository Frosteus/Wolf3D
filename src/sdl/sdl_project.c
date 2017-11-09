/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:06:41 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:06:42 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

void	ft_sdl_project_exec(t_fvoid f, void *data)
{
	if (data == NULL)
		ft_sdl_init();
	TTF_Init();
	if (f != NULL)
		f();
	TTF_Quit();
	SDL_Quit();
}

void	ft_sdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("SDL could not init. SDL Err: %s\n", SDL_GetError());
		exit(errno);
	}
}
