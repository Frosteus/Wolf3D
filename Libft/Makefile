# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 13:16:20 by yskrypny          #+#    #+#              #
#    Updated: 2017/10/27 13:13:00 by yskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors tags
GREENTAG:="\033[1;32m"
YELLOWTAG:="\033[1;33m"
CENDTAG:="\033[0;0m"
#-----------

#Binary name
NAME = libft.a
#Compiler
CC = gcc
#Compiler flags
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = rcs

#Project structure directories
IDIR = include
ODIR = obj
SDIR = src

#All project sources list (norminette demand)
SRCS = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putendl.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_binary_search.c \
	ft_sqrt.c \
	ft_strrev.c \
	ft_str_word_ctr.c \
	ft_quicksort.c \
	ft_get_line.c \
	ft_abs.c \
	ft_fabs.c \
	ft_swap.c \
	ft_itoa_base.c \
	ft_isspace.c
#Creating objects path
OBJS := $(patsubst %.c,$(ODIR)/%.o,$(SRCS))

#Compiling object files
$(ODIR)/%.o:$(SDIR)/%.c
	@echo $(YELLOWTAG)"|\c"
	@$(CC) $(CFLAGS) -I $(IDIR) -c $< -o $@

#Linking binary, adding libs etc.
$(NAME):$(OBJS)
	@echo $(CENDTAG)
	@echo $(GREENTAG)"Linking libft..."
	@ar $(LDFLAGS) $@ $(OBJS)
	@echo "Done."$(CENDTAG)

#all rule
all:	$(NAME)
#defining order that and checking obj dir exists
$(OBJS): | $(ODIR)
#creating obj dir if not exist
$(ODIR):
	@mkdir -p $(ODIR)
#clean rule
clean:
	@echo $(GREENTAG)"Cleaning libft..."
	@rm -rf $(ODIR)
	@echo "Done."$(CENDTAG)
#force clean rule
fclean: clean
	@rm -rf $(NAME)
	@echo $(GREENTAG)"Libft deleted."$(CENDTAG)
#norminette rule
norm:
	@norminette $(SDIR)/$(SRCS)
	@norminette $(IDIR)/*.h
#re rule
re: clean all
#phony defend
.PHONY: all clean fclean re norm
