/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 21:54:13 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 21:54:16 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define S_WID 1900
# define S_HEI 1200
# define WND_NAME "Return to Wolf Doom Nukem"

# define MENU_BTN_NUM 4
# define GUI_ELEM_NUM 6
# define WEAPON_STATE 3
# define WEAPON_DEF_SCALE 5

enum	e_menu_btns
{
	RESUME,
	NEW_GAME,
	OPTIONS,
	EXIT
};
enum	e_gui
{
	GUI_CROSS,
	GUI_HEART,
	GUI_HBAR,
	GUI_HP_BAR,
	GUI_SBAR,
	GUI_ST_BAR
};
enum	e_weap
{
	ASSAULT_RIFLE,
	PISTOL,
	REPEATER,
	HELLSHOT,
	SHOTGUN,
	STATIC_RIFLE,
	BFG9000,
	ROCKET_LNCH,
	GAUSS_GUN,
	LGTN_GUN,
	DOOMDOLL,
	WEAPON_NUM
};
enum	e_anim
{
	WAIT,
	SHOOT,
	RELOAD
};

/*
** Game resource cfg:
*/
# define ASSETS_PATH "assets/"
# define EXT ".png"
# define DIVIDER "/"

# define BUTTONS_PATH ASSETS_PATH"buttons/"
# define MENU_BKGRND ASSETS_PATH"Menu_Background.png"
# define MENU_RESUME_A BUTTONS_PATH"Button_resume_active.png"
# define MENU_RESUME_NA BUTTONS_PATH"Button_resume_inactive.png"
# define MENU_NEW_GAME_A BUTTONS_PATH"Button_new_game_active.png"
# define MENU_NEW_GAME_NA BUTTONS_PATH"Button_new_game_inactive.png"
# define MENU_OPTIONS_A BUTTONS_PATH"Button_options_active.png"
# define MENU_OPTIONS_NA BUTTONS_PATH"Button_options_inactive.png"
# define MENU_EXIT_A BUTTONS_PATH"Button_exit_active.png"
# define MENU_EXIT_NA BUTTONS_PATH"Button_exit_inactive.png"

/*
** Level_maps
*/
# define PATH_MAP ASSETS_PATH"maps/"
# define PATH_MAP_LEVEL1 PATH_MAP"Level1.map"
# define PATH_MAP_LEVEL2 PATH_MAP"Level2.map"
# define PATH_MAP_LEVEL3 PATH_MAP"Level3.map"

# define MAP_MIN 1
# define MAP_MAX 400
# define MAP_PROTECTION 2
# define MAP_PLAYER_OFF 1.5

enum	e_tile_side
{
	SIDE_LIGHT,
	SIDE_DARK,
	SIDE_TOP,
	SIDE_DOWN,
};
enum	e_tile_tex
{
	T0_EMPTY,
	T1_BEDROCK,
	T2_SOULSAND,
	T12_LAVA = 12,
	T16_VENT_SECT = 16,
	T20_RAD_ORE = 20,
	T63_BIOHAZ = 63,
	T69_DR_CHEM_WASTE = 69,
	T77_ACTIVAT = 77
};

typedef enum e_tlprm	t_tlprm;
enum	e_tlprm
{
	NO_TILE_PRM,
	PRM_CAN_WALK,
	PRM_DAMAGE,
	PRM_EXIT
};

/*
** Font:
*/
# define PATH_FONT ASSETS_PATH"fonts/"
# define PATH_GAME_FONT PATH_FONT"Font_game.png"
# define PATH_GAME_FONT_RECT PATH_FONT"font_rect_list.flst"

/*
** Weapon path
*/
# define WEAPON_PATH ASSETS_PATH"weapons/"

/*
** Gui elements path
*/
# define GUI_PATH ASSETS_PATH"gui/"
# define GUI_CROSS_PATH	GUI_PATH"crosshair.png"
# define GUI_HEART_PATH	GUI_PATH"heart.png"
# define GUI_BAR_PATH GUI_PATH"empty_bar.png"
# define GUI_HP_PATH GUI_PATH"health_bar.png"
# define GUI_ST_PATH GUI_PATH"stamina_bar.png"

/*
** Additional sprites
*/
typedef enum e_addspr	t_addspr;
enum	e_addspr
{
	AS_FADE,
	AS_DIAL,
	AS_QUEEN,
	AS_SUCCUB,
	AS_BLOOD,
	AS_GENERAL,
	AS_SKY,
	AS_GM_OV,
	AS_LOAD,
	AS_BIOHAZ,
	AS_END,
	ADD_SPR_NUM
};

# define ADD_SPR_PATH ASSETS_PATH"add/"
# define ADD_SPR_FADE ADD_SPR_PATH"Fade.png"
# define ADD_SPR_DIAL ADD_SPR_PATH"dialog_box.png"
# define ADD_SPR_QUEEN ADD_SPR_PATH"Bad_Black_Queen.png"
# define ADD_SPR_SUC ADD_SPR_PATH"succubus_helper.png"
# define ADD_SPR_BLOOD ADD_SPR_PATH"blood_border.png"
# define ADD_SPR_GENERAL ADD_SPR_PATH"Black_Queen_General_Zodd.png"
# define ADD_SPR_SKY ADD_SPR_PATH"sky_background.png"
# define ADD_SPR_GM_OV ADD_SPR_PATH"game_over.png"
# define ADD_SPR_LOAD ADD_SPR_PATH"Loading.png"
# define ADD_SPR_BIOHAZ ADD_SPR_PATH"biohazard.png"
# define ADD_END ADD_SPR_PATH"end.png"

/*
** Textures
*/
# define PATH_MAP_TEX ASSETS_PATH"textures/"
# define PATH_TEX_LIST PATH_MAP_TEX"all_texture_list.tex"
# define MAP_TEX 89
# define DESTR_TEX 10
# define DESTR_TEX_PREFIX "destroy_stage"

enum	e_map_err
{
	MAP_DATA_ERR,
	MAP_LIMITS_ERR,
	MAP_EXCESS_DATA,
	MAP_LOW_DATA,
	MAP_NO_OFFSET_LEFT,
	MAP_EXCESS_OFFSET
};
/*
** GAMEPLAY PARAMETERS:
**
** Scenes:
*/
typedef enum e_sc	t_sc;
enum	e_sc
{
	SC_MENU,
	SC_GAME,
	SC_GAME_PAUSE,
	SC_OPTIONS,
	SC_CREDITS,
	SC_DEMO,
	SC_RELOAD,
	SC_EXIT
};

# define SCENE_COUNT 8

/*
**  Levels:
*/
typedef enum e_lvlp	t_lvlp;
enum	e_lvlp
{
	LVL_START,
	LVL_DIAL_EV,
	LVL_PLAY,
	LVL_EDIAL_EV,
	LVL_END
};
# define LVL_PARTS 6

# define LVL_NUM 3
# define LVL_1_NAME "LEVEL #1 - THE DOOMDOOMDAY"
# define LVL_2_NAME "LEVEL #2 - NOWHERE EASIER"
# define LVL_3_NAME "LEVEL #3 - RUN, FOREST, RUN!"

enum	e_lvls
{
	LEVEL1,
	LEVEL2,
	LEVEL3
};
typedef enum e_stat_action	t_st_act;
enum	e_stat_action
{
	STAT_MIN,
	STAT_MAX,
	STAT_VAL_LOW,
	STAT_VAL_HIG,
	STAT_SUB,
	STAT_ADD,
	STAT_MULT,
	STAT_DIV
};
/*
** Player speed:
** - move speed;
** - rotation speed;
** - forward sprint speed;
** - back spint speed;
** - stop wall factor
** - distance for mouse block put
*/
# define F_MV 2
# define F_ROT 2
# define F_SPR_FORW 1.8
# define F_SPR_BACK 1.2
# define F_WALL_BL 0.10
# define F_PUT_BL_DIST 2.5

typedef enum e_targ_type	t_tgtp;
enum	e_targ_type
{
	TARG_TILE,
	TARG_ENEMY,
	TARG_EMPTY,
	TARG_BOTH
};
typedef enum e_trg	t_trg;
enum	e_trg
{
	TRIG_NO_EVENT,
	TRIG_LVL_CHANGE,
	TRIG_GAME_WON
};

# define UNUSED(x) (void)(x)

#endif
