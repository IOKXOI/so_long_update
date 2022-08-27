# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 16:38:13 by sydauria          #+#    #+#              #
#    Updated: 2022/08/27 22:03:04 by sydauria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef VERBOSE
#MAKEFLAGS += --no-print-directory --silence
#endif

NAME=so_long
SRCDIR=./srcs/**/
OBJSDIR=./objs/
LIBDIR=./libdir/
HEADERSDIR=includes
PATH_MLX=./minilibx-linux/
PATH_LIBFT=./libft/

SRC=checker_arg.c\
	succes.c\
	check_ressources.c\
	checker_map.c\
	check_walls.c\
	map_converter.c\
	display_map.c\
	display_hero.c\
	display_elements.c\
	error_management.c\
	error_management2.c\
	keyhook.c\
	enemies.c\
	display_enemies.c\
	display_frame.c\
	enemies_mooves.c\
	init.c\
	predict_moove.c\
	random.c\
	collect.c\
	main.c\
	display_mooves.c\

SRCS=$(addprefix $(SRCDIR), $(SRC))
OBJ=$(SRC:.c=.o) 
OBJS=$(addprefix $(OBJSDIR),$(OBJ))
DEPS=$(OBJS:.o=.d)
CC=gcc
FLAGS= -g -MMD -I $(HEADERSDIR)
CFLAGS= -Wall -Werror -Wextra -g -MMD -I $(HEADERSDIR)
INCLUDES= -I$(HEADERSDIR) -I$(PATH_LIBFT) $(MLX) $(LIBFT)
MLX= -L$(PATH_MLX) -lmlx -lXext -lX11 -lm
LIBFT= -L$(PATH_LIBFT) -lft
DEBUG= -g

################################################################################
#                                 COLORS                                       #
################################################################################

NO_COLOR 		=	\033[m
OK_COLOR		=	\033[31m
ERROR_COLOR		=	\033[38;5;1m
WARN_COLOR		=	\033[38;5;3m
SILENT_COLOR	=	\033[38;5;245m
INFO_COLOR		=	\033[38;5;140m
OBJ_COLOR		=	\033[0;36m
COLOUR_GREEN	=	\033[0;32m
COLOUR_RED		=	\033[0;31m
COLOUR_BLUE		=	\033[0;34m
COLOUR_END		=	\033[0m
BOLD			=	\033[1m

all:$(NAME)

$(NAME): $(PATH_MLX)libmlx.a $(OBJS)
		@echo "$(INFO_COLOR)All objects for $(COLOUR_RED)$(BOLD)$(NAME)$(COLOUR_END)$(COLOUR_END) $(INFO_COLOR)where successfully created.\n$(COLOUR_END)"
		$(MAKE) -C $(PATH_LIBFT) all --quiet
		@echo "\n$(NO_COLOR)======= $(INFO_COLOR) Start Compilation for ${NAME} $(NO_COLOR)=======\n"	
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT)
		@echo "\n"
		@echo "$(INFO_COLOR)$(NAME)$(NO_COLOR) successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

$(OBJSDIR)%.o: $(SRCDIR)%.c $(HEADERSDIR)/so_long.h
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BOLD)$(INFO_COLOR)Created : $(COLOUR_RED)$(BOLD)$@$(OK_COLOR)✓$(NO_COLOR)$(COLOUR_END)$(SILENT_COLOR)"

$(PATH_MLX)libmlx.a:
	@echo "$(COLOUR_END)$(COLOUR_BLUE)compilation for :$(BOLD)$(PATH_MLX)\n"
	$(MAKE) -C $(PATH_MLX) all --quiet
	@echo "$(COLOUR_BLUE)$(PATH_MLX) compilated.$(COLOUR_END)$(OK_COLOR)✓$(NO_COLOR)\n"

clean:
	@echo "$(COLOUR_BLUE)"
	$(MAKE) -C $(PATH_LIBFT) clean
	rm -f $(OBJS)
	@echo "$(COLOUR_END)"

bonus:$(NAME)

fclean: clean
	@echo "$(COLOUR_BLUE)"
	$(MAKE) -C $(PATH_LIBFT) fclean
	$(MAKE) -C $(PATH_MLX) clean --quiet --jobs
	rm -f $(NAME)
	rm -rf $(OBJSDIR)
	@echo "$(COLOUR_BLUE)Removed $(NAME)$(NO_COLOR).\n"
	@echo "$(COLOUR_END)"

re: fclean all

print-% : ; @echo $* = $($*)

-include:$(DEPS)

.PHONY: re all clean fclean
