/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 22:25:00 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 22:25:01 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_scene_set(t_id *id)
{
	if ((id->scene = malloc(sizeof(t_fscene) * SCENE_COUNT)) == NULL)
		ft_errors_general(ERR_MALLOC);
	id->scene[SC_MENU].sc = (void *)ft_menu_create(id->lprm->wnd);
	id->scene[SC_MENU].fun = (void *)ft_scene_menu;
	id->scene[SC_GAME].sc = (void *)ft_game_scene_create(id->lprm->wnd);
	id->scene[SC_GAME].fun = (void *)ft_scene_game;
	id->scene[SC_GAME_PAUSE].sc = id->scene[SC_MENU].sc;
	id->scene[SC_GAME_PAUSE].fun = (void *)ft_scene_game_pause;
	id->scene[SC_OPTIONS].sc = NULL;
	id->scene[SC_OPTIONS].fun = NULL;
	id->scene[SC_CREDITS].sc = NULL;
	id->scene[SC_CREDITS].fun = NULL;
	id->scene[SC_DEMO].sc = NULL;
	id->scene[SC_DEMO].fun = NULL;
	id->scene[SC_RELOAD].sc = id->scene[SC_GAME].sc;
	id->scene[SC_RELOAD].fun = (void *)ft_scene_reload;
	id->scene[SC_EXIT].sc = (void *)id;
	id->scene[SC_EXIT].fun = (void *)ft_scene_exit;
}

t_sc	ft_scene_menu(t_sc c_sc, t_lprm *lprm, t_menu *menu)
{
	SDL_SetRelativeMouseMode(SDL_FALSE);
	ft_sdl_sprite_show(menu->bkgrnd_spr, NULL, SPR_SPR_TO_SCR);
	ft_sdl_btn_state_set(&menu->p->arr[0][RESUME], NO_FLAG);
	c_sc = ft_scene_menu_general_op(c_sc, lprm, menu);
	return (c_sc);
}

t_sc	ft_scene_game_pause(t_sc c_sc, t_lprm *lprm, t_menu *menu)
{
	SDL_SetRelativeMouseMode(SDL_FALSE);
	ft_sdl_sprite_show(menu->bkgrnd_spr, NULL, SPR_SPR_TO_SCR);
	ft_sdl_btn_state_set(&menu->p->arr[0][RESUME], IS_AV);
	c_sc = ft_scene_menu_general_op(c_sc, lprm, menu);
	return (c_sc);
}

t_sc	ft_scene_game(t_sc c_sc, t_lprm *lprm, t_game *g)
{
	t_lvl	*l;

	if (g->pl->hp.st.val == 0)
	{
		SDL_RenderCopy(lprm->wnd->r, g->buff.add[AS_GM_OV]->tex->t, NULL, NULL);
		if (lprm->e.key.keysym.sym == SDLK_RETURN)
			c_sc = SC_MENU;
	}
	else if (g->lvl[LEVEL3].win_trig.bool == true)
	{
		ft_sdl_sprite_show(g->buff.add[AS_END], NULL, SPR_SPR_TO_SCR);
		if (lprm->efl == true && lprm->e.type == SDL_KEYDOWN)
			if (lprm->e.key.keysym.sym == SDLK_RETURN)
				c_sc = SC_MENU;
	}
	else
	{
		SDL_SetRelativeMouseMode(SDL_TRUE);
		l = &g->lvl[g->c_lvl];
		l->part[l->c_lvlp].fun(lprm, g, l);
	}
	return (c_sc);
}

t_sc	ft_scene_exit(t_sc c_sc, t_id *id)
{
	id->loop = false;
	return (c_sc);
}
