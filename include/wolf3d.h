/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 19:56:02 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# ifdef _WIN32
#  define _CRTDBG_MAP_ALLOC
#  include <stdlib.h>
#  include <crtdbg.h>
# endif
# include <fcntl.h>
# include "libft.h"
# include "sdl_project.h"
# include "defines.h"

typedef struct s_fscene	t_fscene;
typedef struct s_flvl	t_flvl;
typedef struct s_trig	t_trig;
typedef struct s_anim	t_anim;
typedef struct s_cam	t_cam;
typedef struct s_smod	t_smod;
typedef struct s_cstat	t_cstat;
typedef struct s_stmd	t_stmd;
typedef struct s_targ	t_targ;
typedef struct s_weap	t_weap;
typedef struct s_player	t_pl;
typedef struct s_tbuff	t_tbuff;
typedef struct s_tile	t_tile;
typedef struct s_map	t_map;
typedef struct s_menu	t_menu;
typedef struct s_dial	t_dial;
typedef struct s_rayc	t_rayc;
typedef struct s_gui	t_gui;
typedef	struct s_lvl	t_lvl;
typedef struct s_game	t_game;
typedef struct s_lprm	t_lprm;
typedef struct s_id		t_id;

struct	s_fscene
{
	void	*sc;
	t_sc	(*fun)(t_sc c_sc, t_lprm *lprm, void *prm);
};

struct	s_flvl
{
	void	(*fun)(t_lprm *prm, t_game *g, t_lvl *lvl);
};

struct	s_trig
{
	t_trg	type;
	t_p		map_pos;
	int		tl_val;
	t_bool	bool;
};

struct	s_anim
{
	int	f_st;
	int	f_end;
	int	tot_frames;
	int	f_delay;
	int	tot_time;
};

struct	s_cam
{
	t_v2d	pos;
	int		h_off_av;
};

struct	s_smod
{
	double		val;
	double		et;
	double		dt;
	t_st_act	act;
};

struct	s_cstat
{
	double	val;
	double	max;
	double	min;
};

struct	s_stmd
{
	t_cstat	st;
	t_smod	reg;
	t_smod	deg;
};

struct	s_targ
{
	int		x[2];
	int		y[2];
	t_tgtp	t;
};

struct	s_weap
{
	t_spr_p	**spr;
	t_anim	anim[WEAPON_STATE];
	double	timer;
	double	fr_cntr;
	int		fr;
	int		dmg;
	int		ammo;
	int		w_st;
};

struct	s_player
{
	t_v2d	pos;
	t_v2d	dir;
	t_cam	cam;
	t_targ	targ;
	double	mv_sp;
	double	rot_speed;
	t_stmd	hp;
	t_stmd	st;
};

struct	s_tbuff
{
	t_spr	**mtn;
	t_spr	**mtd;
	t_spr	**dt;
	t_spr	**add;
	Uint8	alpha;
	int		mt_num;
	int		dt_num;
};

struct	s_tile
{
	t_spr	*side[4];
	t_spr	*eff;
	t_stmd	hp;
	int		val;
};

struct	s_map
{
	t_tile	**m;
	int		w;
	int		h;
};

struct	s_menu
{
	t_spr	*bkgrnd_spr;
	t_panel	*p;
};

struct	s_dial
{
	int		d_flag;
	int		d_tm;
	char	*name;
	char	*txt;
	t_spr	*port;
	t_drect	pos[3];
};

struct	s_rayc
{
	t_v2d		dir;
	t_v2d		del_dist;
	double		ln_sz;
	double		side_dist_x;
	double		side_dist_y;
	t_p			map;
	int			x;
	int			hwid;
	int			side;
	int			st_x;
	int			st_y;
	double		w_dist;
	int			tex_lnhei;
	int			dr_st;
	int			dr_end;
	t_tile		*tile;
	int			tex_w;
	int			tex_h;
	SDL_Rect	src;
	SDL_Rect	dest;
	double		wall_x;
};

struct	s_lvl
{
	const char	*name;
	const char	*map_name;
	t_flvl		part[LVL_PARTS];
	t_lvlp		c_lvlp;
	t_map		map;
	t_trig		win_trig;
	t_timer		lvl_tm;
};

struct	s_gui
{
	t_spr	**bs;
};

struct	s_game
{
	t_pl	*pl;
	t_weap	**weap;
	int		sel_w;
	t_timer	tm;
	t_tbuff	buff;
	t_sprbf	*gfont;
	t_dial	d;
	t_gui	gui;
	t_lvl	*lvl;
	int		c_lvl;
};

struct	s_lprm
{
	t_wnd		*wnd;
	t_v2d		xy_sc;
	t_p			base_sc;
	SDL_Event	e;
	t_bool		efl;
	const Uint8 *ks;
	t_p			ms_coord;
};

struct	s_id
{
	t_lprm		*lprm;
	t_fscene	*scene;
	t_bool		loop;
};
/*
**main.c
*/
t_rayc	ft_wold_loop_set_ray_cast(t_pl *pl, t_wnd *w);
void	ft_wolf_raycasting_all(t_wnd *w, t_map *map, t_pl *pl);
void	ft_wolf_draw_sky_and_ground(t_wnd *w, t_tbuff *b, t_pl *pl);
void	ft_wolf3d(void);
/*
** animation.c
*/
t_anim	ft_animation_set(int f_st, int f_end, int f_delay);
void	ft_animation_set_total_anim_time(t_anim *a, int total_time);
/*
** controls_game.c
** controls_game_movement.c
** controls_game_rotation_looking.c
** controls_general.c
** controls_menu.c
** controls_game_weapon.c
*/
void	ft_game_controls_use(t_lprm *lprm, t_game *g, t_pl *pl, t_map *map);
void	ft_game_controls(t_lprm *lprm, t_game *g, t_lvl *lvl);
void	ft_game_controls_mouse(t_lprm *lprm, t_game *g);
double	ft_game_ctrl_spr(double t, const Uint8 *ks, t_pl *pl, double f_spr);
void	ft_gctrl_mv_back(t_pl *pl, const Uint8 *ks, double ct, t_map *map);
void	ft_gctrl_mv_frw(t_pl *pl, const Uint8 *ks, double ct, t_map *map);
void	ft_gctrl_mv_left(t_pl *pl, const Uint8 *ks, t_map *map);
void	ft_gctrl_mv_rght(t_pl *pl, const Uint8 *ks, t_map *map);
void	ft_game_ctrl_look_up(t_pl *pl, const Uint8 *ks);
void	ft_game_ctrl_look_down(t_pl *pl, const Uint8 *ks);
void	ft_game_ctrl_rot_left(t_pl *pl, double b_spd);
void	ft_game_ctrl_rot_right(t_pl *pl, double b_spd);
void	ft_game_controls_weapon(t_lprm *lprm, t_game *g);
void	ft_controls_game_weap_set(SDL_Event *e, t_game *g);
void	ft_general_keydown_check(t_id *id, t_sc *c_sc);
void	ft_menu_controls(t_sc *c_sc, t_lprm *lprm, t_menu *menu);
/*
** dialog.c
** dialog1_lvl1.c
** dialog2_lvl1.c
** dialog1_lvl2.c
*/
void	ft_dialog_box_show(t_wnd *w, t_game *g, t_dial *d);
void	ft_dialog_box_skip(t_lprm *lprm, t_game *g, t_lvl *lvl);
void	ft_lvl1_queen_dialog(t_wnd *w, t_game *g);
void	ft_lvl1_queen_dialog_2(t_wnd *w, t_game *g);
void	ft_lvl2_queen_dialog_1(t_wnd *w, t_game *g);
t_dial	ft_lvl1_dialog_replica_1(t_tbuff *b);
t_dial	ft_lvl1_dialog_replica_2(t_tbuff *b);
t_dial	ft_lvl1_dialog_replica_3(t_tbuff *b);
t_dial	ft_lvl1_dialog_replica_4(t_tbuff *b);
t_dial	ft_lvl1_dialog_replica_5(t_tbuff *b);
t_dial	ft_lvl1_dialog2_replica_1(t_tbuff *b);
t_dial	ft_lvl1_dialog2_replica_2(t_tbuff *b);
t_dial	ft_lvl1_dialog2_replica_3(t_tbuff *b);
t_dial	ft_lvl1_dialog2_replica_4(t_tbuff *b);
t_dial	ft_lvl2_dialog_replica_1(t_tbuff *b);
t_dial	ft_lvl2_dialog_replica_2(t_tbuff *b);
/*
** game.c
*/
void	ft_game_player_stat_set(t_pl *pl);
t_pl	*ft_game_player_create(t_wnd *w);
void	ft_game_general_prm(t_game *g);
void	ft_game_restart(t_wnd *w, t_game *g);
t_game	*ft_game_scene_create(t_wnd *w);

/*
** game_font.c
*/
void	ft_font_dim_parse(int fd, SDL_Rect *r);
t_sprbf	*ft_font_rect_parse(int sz, int fd, t_tex *t);
t_sprbf	*ft_font_parse(SDL_Renderer *r);
void	ft_font_txtbox(t_sprbf *gf, SDL_Rect box, const char *txt, double sc);
/*
** gameplay.c
** gameplay_2.c
*/
void	ft_gameplay_place_tile(t_pl *pl, t_map *map, t_tbuff *b);
void	ft_map_set_tile_hp(t_tile *t);
void	ft_gameplay_block_destr_tex(t_tile *t, t_tbuff *b);
void	ft_gameplay_block_shoot(t_pl *pl, t_weap *w, t_map *map, t_tbuff *b);
void	ft_regen_hp_and_stamina(t_pl *pl, double ct);
t_targ	ft_target_set(t_tgtp type, int pos_x, int pos_y);
int		ft_player_around_map_check_2(t_p *p, t_map *map);
int		ft_player_around_map_check(t_p p, t_map *map);
void	ft_block_player_damage(t_wnd *w, t_game *g, t_pl *pl, t_map *map);
/*
** gui.c
*/
void	ft_gui_set(t_wnd *w, t_gui *gui);
void	ft_gui_show(t_wnd *w, t_gui *gui, t_pl *pl);
/*
** init.c
*/
t_lprm	*ft_init_loop_sdl_prm(void);
void	ft_init_application_prm(t_id *id);
/*
** level_1.c
*/
void	ft_lvl1_setting_up(t_lprm *lprm, t_game *g, t_lvl *lvl);
void	ft_lvl1_dial_event(t_lprm *lprm, t_game *g, t_lvl *lvl);
void	ft_lvl1_dial_event_2(t_lprm *lprm, t_game *g, t_lvl *lvl);
void	ft_lvl1_gameplay(t_lprm *lprm, t_game *g, t_lvl *lvl);
/*
** level_2.c
*/
void	ft_lvl2_setting_up(t_lprm *lprm, t_game *g, t_lvl *lvl);
void	ft_lvl2_dial_event(t_lprm *lprm, t_game *g, t_lvl *lvl);
void	ft_lvl2_gameplay(t_lprm *lprm, t_game *g, t_lvl *lvl);
/*
** level_3.c
*/
void	ft_lvl3_setting_up(t_lprm *lprm, t_game *g, t_lvl *lvl);
void	ft_lvl3_gameplay(t_lprm *lprm, t_game *g, t_lvl *lvl);
/*
** level_general.c
*/
void	ft_init_lvl1(t_lvl *lvl);
void	ft_init_lvl2(t_lvl *lvl);
void	ft_init_lvl3(t_lvl *lvl);
void	ft_level_part_lvl_num_change(t_game *g);
void	ft_lvl_end(t_lprm *lprm, t_game *g, t_lvl *lvl);
/*
** loop_management.c
*/
void	ft_loop_regular_operations(t_lprm *lprm, t_game *g);
void	ft_game_loop_regular_operation(t_lprm *lprm, t_game *g, t_lvl *lvl);
/*
** map_parser_1.c
** map_parser_2.c
** map_parser_3.c
*/
t_tile	**ft_create2d_tile_array(size_t col, size_t row);
void	ft_map_bedrock_filling(t_map *map);
void	ft_map_add_texture(t_tbuff *b, t_map *map);
void	ft_map_parse(t_tbuff *b, t_lvl *lvl, t_pl *pl);
void	ft_map_parse_errors(int err);
void	ft_map_parse_num_lim(char *str, int *num, int lmin, int lmax);
void	ft_map_parse_position_and_start(t_lvl *lvl, t_pl *pl, int fd);
char	*ft_map_get_offset(int *off, char *str);
void	ft_free_split_char_arr(char **split);
void	ft_map_parse_line(t_map *map, char *str, int i);
void	ft_map_filling(t_map *map, int fd);
/*
** menu.c
** menu_buttons.c
** menu_buttons_onclick.c
*/
void	ft_menu_load_background(SDL_Renderer *r, t_menu *m);
void	ft_menu_btn_arrange(t_wnd *w, t_menu *menu);
t_menu	*ft_menu_create(t_wnd *w);
t_btn	*ft_menu_btn_selection(t_menu *menu, t_p ms_coord);
void	ft_menu_btn_deselection(t_btn *b);
t_btn	*ft_menu_btn_resume(t_wnd *w);
t_btn	*ft_menu_btn_new_game(t_wnd *w);
t_btn	*ft_menu_btn_options(t_wnd *w);
t_btn	*ft_menu_btn_exit(t_wnd *w);
t_sc	ft_resume_click(void);
t_sc	ft_new_game_click(void);
t_sc	ft_options_click(void);
t_sc	ft_exit_click(void);
/*
** resource_free.c
*/
void	ft_sdl_destroy_wnd_and_renderer(t_wnd *w);
void	ft_free_texture_buffer(t_tbuff *b);
void	ft_free_texture_gui(t_gui *gui);
void	ft_free_resources(t_id *id);
/*
** scenes.c
** scenes_general_operation.c
*/
void	ft_scene_set(t_id *id);
t_sc	ft_scene_menu(t_sc c_sc, t_lprm *lprm, t_menu *menu);
t_sc	ft_scene_game_pause(t_sc c_sc, t_lprm *lprm, t_menu *menu);
t_sc	ft_scene_game(t_sc c_sc, t_lprm *lprm, t_game *g);
t_sc	ft_scene_exit(t_sc c_sc, t_id *id);
void	ft_scene_show_blood_splat(t_spr *blood, t_pl *pl);
t_sc	ft_scene_menu_general_op(t_sc c_sc, t_lprm *lprm, t_menu *menu);
t_sc	ft_scene_reload(t_sc c_sc, t_lprm *lprm, t_game *g);
/*
** service_function_1.c
*/
char	*ft_path_catstr(char *r_path, char *name, int i, int off);
t_v2d	ft_game_move_restr(t_v2d pos, t_v2d dir, double c_mvspd, int sign);
int		ft_game_move_possible(t_tile **m, double r1, double r2, double wb);
t_tile	*ft_map_get_tile(t_map *map, int map_x, int map_y);
/*
** service_function_2.c
*/
void	ft_game_player_reload(t_wnd *w, t_game *g);
void	ft_game_free_maps_and_lvls(t_game *g);
void	ft_game_lvl_reload(t_game *g);
int		ft_map_get_cond_val(t_p p, t_map *m);
/*
** stat_manage.c
*/
t_cstat	ft_stat_set(int val, int min, int max);
t_smod	ft_stat_mod_set(int val, t_st_act act, double tt);
int		ft_stat_check(t_cstat *st, double val, t_st_act act);
void	ft_stat_action(t_cstat *st, double val, t_st_act act);
void	ft_stat_mod(t_cstat *st, t_smod *mod, double dt);
/*
** texture_load.c
** texture_parse.c
*/
void	ft_tex_load_additional(t_tbuff *b, t_wnd *w);
void	ft_tex_additional_free(t_tbuff *b);
void	ft_texbuff_set_constant_prm(t_tbuff *b);
void	ft_texture_parser(t_tbuff *b, SDL_Renderer *r);
void	ft_texture_destr_parser(t_tbuff *b, SDL_Renderer *r, int num);
/*
** trigger.c
*/
t_trig	ft_trigger_set(int x, int y, int tl_val, t_trg type);
void	ft_trigger_set_to_default(t_trig *triggers, int num, t_trg type);
/*
** weapon.c
** weapon_buffer.c
** weapon_load_1.c
** weapon_load_2.c
*/
void	ft_weapon_action(t_lprm *lprm, t_game *g);
void	ft_weapon_unload_all_free_inventory(t_game *g);
void	ft_weapon_create_inventory_load_all(SDL_Renderer *r, t_game *g);
void	ft_weapon_set_all_ammo_and_damage(t_game *g);
void	ft_weapon_set_dmg_and_ammo(t_weap *w, int dmg, int ammo);
void	ft_weapon_buffer_pos_and_scale(t_weap *w, t_v2d pos, double sc, t_p ft);
void	ft_weapon_create_inventory(t_game *g, int weap_num);
t_weap	*ft_weapon_sprites_load(SDL_Renderer *re, int fr, char *fn);
void	ft_weapon_spritebuff_free(t_weap *w);
void	ft_weapon_load_pistol(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_repeater(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_hellshot(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_shotgun(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_static_rifle(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_bfg9000(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_rocket_launcher(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_gauss_gun(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_heavy_assault_rifle(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_lightning_gun(SDL_Renderer *r, t_game *g);
void	ft_weapon_load_doomdoll(SDL_Renderer *r, t_game *g);
/*
** wolf_raycasting_1.c
*/
void	ft_wolf_raycast_find_delta(t_rayc *rc, t_pl *pl);
void	ft_wolf_raycast_find_side_dist(t_rayc *rc, t_pl *pl);
void	ft_wolf_raycast_find_hit_block(t_rayc *rc, t_pl *pl, t_map *map);
void	ft_wolf_raycast_find_wall_dist(t_rayc *rc, t_pl *pl, int w_hei);
void	ft_wolf_raycast_texture(t_rayc *rc, t_pl *pl, t_wnd *w);
/*
** to_lib.c
*/
double	ft_drand(double min, double max);
int		**ft_create2d_int_array(size_t col, size_t row);
void	ft_free_2d_array(void **arr);
int		ft_get_file_fd(const char *f_name);

#endif
