/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_error_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:05:35 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:05:37 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_project.h"

void	ft_sdl_log_errors(int err)
{
	if (err == 99)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't get texture size: %s", SDL_GetError());
	if (err == 100)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't load texture: %s", SDL_GetError());
	if (err == 101)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't create window and renderer: %s", SDL_GetError());
	if (err == 102)
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
		"Couldn't create window: %s", SDL_GetError());
	exit(0);
}
