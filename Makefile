# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 16:38:13 by sydauria          #+#    #+#              #
#    Updated: 2022/08/25 20:40:26 by sydauria         ###   ########.fr        #
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
	enemies_mooves.c\
	init.c\
	predict_moove.c\
	random.c\
	main.c\
	display_mooves.c\

SRCS=$(addprefix $(SRCDIR), $(SRC))
OBJ=$(SRC:.c=.o) 
OBJS=$(addprefix $(OBJSDIR),$(OBJ))
DEPS=$(OBJS:.o=.d)

CC= gcc
FLAGS= -g -MMD -I $(HEADERSDIR)
CFLAGS= -Wall -Werror -Wextra -g -MMD -I $(HEADERSDIR)
INCLUDES= -I$(HEADERSDIR) -I$(PATH_LIBFT) $(MLX) $(LIBFT)
MLX= -L$(PATH_MLX) -lmlx -lXext -lX11 -lm
LIBFT= -L$(PATH_LIBFT) -lft
DEBUG= -g

################################################################################
#                                 COLORS                                       #
################################################################################

NO_COLOR 		=	\033[38;5;15m
OK_COLOR		=	\033[38;5;2m
ERROR_COLOR		=	\033[38;5;1m
WARN_COLOR		=	\033[38;5;3m
SILENT_COLOR	=	\033[38;5;245m
INFO_COLOR		=	\033[38;5;140m
OBJ_COLOR		=	\033[0;36m


all:$(NAME)

$(NAME):$(PATH_MLX)libmlx.a $(OBJS)
		printf "\t$(NO_COLOR)All objects for $(INFO_COLOR)$(NAME) $(NO_COLOR)where successfully created.\n"
		$(MAKE) -C $(PATH_LIBFT)
		printf "\t$(INFO_COLOR)$(NAME) $(NO_COLOR)Removed all objects$(NO_COLOR).\n"
		printf "\n\t$(NO_COLOR)-------- $(INFO_COLOR) Start Compilation for ${NAME} $(NO_COLOR)--------\n"	
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT)
		printf "2s \r"
		printf "\t$(INFO_COLOR)$(NAME)$(NO_COLOR) successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

$(OBJSDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "\t\t\t$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

$(PATH_MLX)libmlx.a:
	$(MAKE) -C $(PATH_MLX) all --quiet
	printf "\033[32;1m%s OK%40.40s\n\033[0m" $(PATH_MLX) ""

.c.o:
	$(CC) -c $< -o $(<:.c=.o) $(CFLAGS)
	mv *.o ./(OBJSDIR)

clean:
	$(MAKE) -C $(PATH_LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(PATH_LIBFT) fclean
	$(MAKE) -C $(PATH_MLX) clean --quiet --jobs
	rm -f $(NAME)
	rm -rf $(OBJSDIR)
	printf "\t\t$(INFO_COLOR)$(NAME) $(NO_COLOR)Removed $(INFO_COLOR)$(NAME)$(NO_COLOR).\n"


re: fclean all

print-% : ; @echo $* = $($*)

-include:$(DEPS)

.PHONY: re all clean fclean 

