/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_game_rotation_looking.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:21:56 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/24 15:21:57 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_game_ctrl_look_up(t_pl *pl, const Uint8 *ks)
{
	if (ks[SDL_SCANCODE_PAGEUP])
		pl->cam.h_off_av++;
}

void	ft_game_ctrl_look_down(t_pl *pl, const Uint8 *ks)
{
	if (ks[SDL_SCANCODE_PAGEDOWN])
		pl->cam.h_off_av--;
}

void	ft_game_ctrl_rot_left(t_pl *pl, double b_spd)
{
	double	old_dir;
	double	old_plane;
	double	sin_rot;
	double	cos_rot;

	sin_rot = sin(pl->rot_speed * b_spd);
	cos_rot = cos(pl->rot_speed * b_spd);
	old_dir = pl->dir.x;
	pl->dir.x = pl->dir.x * cos_rot - pl->dir.y * sin_rot;
	pl->dir.y = old_dir * sin_rot + pl->dir.y * cos_rot;
	old_plane = pl->cam.pos.x;
	pl->cam.pos.x = pl->cam.pos.x * cos_rot - pl->cam.pos.y * sin_rot;
	pl->cam.pos.y = old_plane * sin_rot + pl->cam.pos.y * cos_rot;
}

void	ft_game_ctrl_rot_right(t_pl *pl, double b_spd)
{
	double	old_dir;
	double	old_plane;
	double	sin_rot;
	double	cos_rot;

	sin_rot = sin(-pl->rot_speed * b_spd);
	cos_rot = cos(-pl->rot_speed * b_spd);
	old_dir = pl->dir.x;
	pl->dir.x = pl->dir.x * cos_rot - pl->dir.y * sin_rot;
	pl->dir.y = old_dir * sin_rot + pl->dir.y * cos_rot;
	old_plane = pl->cam.pos.x;
	pl->cam.pos.x = pl->cam.pos.x * cos_rot - pl->cam.pos.y * sin_rot;
	pl->cam.pos.y = old_plane * sin_rot + pl->cam.pos.y * cos_rot;
}
