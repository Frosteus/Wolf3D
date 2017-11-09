# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 13:16:20 by yskrypny          #+#    #+#              #
#    Updated: 2017/11/08 23:16:31 by yskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#all rule

#Colors tags
GREENTAG:="\033[1;32m"
YELLOWTAG:="\033[1;33m"
REDTAG:="\033[1;31m"
CENDTAG:="\033[0;0m"
#-----------

#Detecting shell OS name
OS = $(shell uname -s)
#Binary name
NAME = wolf3d
#Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(LSDL2)
LDFLAGS = rcs
# lib flags for Apple
ifeq ($(OS), Darwin)
	LBFLAGS = -framework SDL2 -framework SDL2_ttf -framework SDL2_image $(LFT)
	LSDL2 = -F./SDL2_Library -O3
endif
#libflags for Linux
ifeq ($(OS), Linux)
	LBFLAGS = -lm $(LFT) -std=gnu99
	LSDL2 = -lSDL2 -lSDL2_ttf -lSDL2_image
endif
#libft path
LFTDIR = Libft
LFT = $(LFTDIR)/libft.a
#Project structure directories
IDIR = include
LIDIR = Libft/include
ODIR = obj
SDIR = src
#All project sources list (norminette demand)
SRCS = animation.c\
	ft_errors.c\
	game_font.c\
	game.c\
	gui.c\
	init.c\
	loop_management.c\
	main.c\
	resource_free.c\
	service_functions_1.c\
	service_functions_2.c\
	stats_manage.c\
	to_lib.c\
	trigger.c\
	wolf_raycasting_1.c\
	controls/controls_game.c\
	controls/controls_game_movement.c\
	controls/controls_game_rotation_looking.c\
	controls/controls_game_weapon.c\
	controls/controls_general.c\
	controls/controls_menu.c\
	dialogs/dialog.c\
	dialogs/dialog1_lvl1.c\
	dialogs/dialog1_lvl2.c\
	dialogs/dialog2_lvl1.c\
	dialogs/dialog_lvl.c\
	gameplay/gameplay.c\
	gameplay/gameplay_2.c\
	map_parsing/map_parser_1.c\
	map_parsing/map_parser_2.c\
	map_parsing/map_parser_3.c\
	menu_and_buttons/menu.c\
	menu_and_buttons/menu_buttons.c\
	menu_and_buttons/menu_buttons_onclick.c\
	scenes_and_levels/level_1.c\
	scenes_and_levels/level_2.c\
	scenes_and_levels/level_3.c\
	scenes_and_levels/level_general.c\
	scenes_and_levels/scenes.c\
	scenes_and_levels/scenes_general_operation.c\
	sdl/sdl_button.c\
	sdl/sdl_button_array.c\
	sdl/sdl_error_management.c\
	sdl/sdl_panel.c\
	sdl/sdl_project.c\
	sdl/sdl_rect_convert.c\
	sdl/sdl_rect_set.c\
	sdl/sdl_sprite_1_create.c\
	sdl/sdl_sprite_2_create.c\
	sdl/sdl_sprite_buffer.c\
	sdl/sdl_sprite_draw.c\
	sdl/sdl_surface.c\
	sdl/sdl_text_output.c\
	sdl/sdl_texture.c\
	sdl/sdl_timer.c\
	sdl/sdl_window_create.c\
	sdl/sdl_window_manage_prm.c\
	textures/texture_load.c\
	textures/texture_parse.c\
	weapons/weapon.c\
	weapons/weapon_buffer.c\
	weapons/weapon_load_1.c\
	weapons/weapon_load_2.c\
	weapons/weapon_load_3.c
#Creating objects path
OBJS := $(patsubst %.c,$(ODIR)/%.o,$(SRCS))

#Compiling object files
$(ODIR)/%.o:$(SDIR)/%.c
	@mkdir -p $(dir $@)
	@echo $(YELLOWTAG)"|\c"
	@$(CC) $(CFLAGS) -I $(IDIR) -I $(LIDIR) -c $< -o $@

#Linking binary, adding libs etc.
$(NAME):$(OBJS)
	@echo $(CENDTAG)
	@make -C $(LFTDIR)
	@echo "Mlx lib ready"
	@echo $(GREENTAG)"Linking project..."
	@$(CC) -o $@ $^ $(CFLAGS) $(LBFLAGS) -pg
	@echo "Done."$(CENDTAG)

#defining order and checking that obj dir exists
$(OBJS): | $(ODIR)
#creating obj dir if not exist
$(ODIR):
	@mkdir -p $(ODIR)

all: $(NAME)

#clean rule
clean:
	@echo $(YELLOWTAG)"Cleaning project..."
	@rm -rf $(ODIR)
	@echo "Done."$(CENDTAG)
	@make clean -C $(LFTDIR)
#full clean rule
fclean: clean
	@make fclean -C $(LFTDIR)
	@rm -rf $(NAME)
	@echo $(REDTAG)"Project deleted."$(CENDTAG)
#norminette rule
norm:
	@norminette $(SDIR)/*.c
	@norminette $(IDIR)/*.h
#re rule
re: clean all
sdl:
	cp -r SDL2_Library/SDL2_image.framework ~/Library/Frameworks/
	cp -r SDL2_Library/SDL2.framework ~/Library/Frameworks/
	cp -r SDL2_Library/SDL2_ttf.framework ~/Library/Frameworks/
#phony defend
.PHONY: all clean fclean re norm
