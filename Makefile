# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 17:02:37 by ubuntu            #+#    #+#              #
#    Updated: 2024/12/29 19:49:49 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
SRCS_DIR	= srcs
OBJ_DIR 	= obj_so_long
SRCS		= srcs/error_messages/error_messages.c \
			srcs/flood_fill/flood_fill_management.c \
			srcs/flood_fill/flood_fill.c \
			srcs/game/game.c \
			srcs/game/game_1.c \
			srcs/game/game_2.c \
			srcs/game/game_management.c \
			srcs/make_map/make_map.c \
			srcs/map_parsing/map_parsing_management.c \
			srcs/map_parsing/map_parsing.c \
			srcs/map_parsing/map_parsing_1.c \
			srcs/file_parsing/file_parsing_management.c \
			srcs/file_parsing/file_parsing.c \
			srcs/tools/tools.c \
			srcs/tools/tools_1.c \
			srcs/tools/gnl.c \
			srcs/main.c
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -ggdb -I$(SRCS_DIR) -Ilib/minilibx-linux
MLX_LIB		= lib/minilibx-linux/libmlx.a
MLX_FLAGS	= -Llib/minilibx-linux -lmlx -lXext -lX11

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX_LIB)
			$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
			@echo "\033[32m""Compilation de $(NAME) est terminée avec MiniLibX !""\033[0m"

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
			@make -C lib/minilibx-linux
			@echo "\033[36m""MiniLibX compilée avec succès !""\033[0m"

clean:
			$(RM) $(OBJ_DIR)
			@make clean -C lib/minilibx-linux
			@echo "\033[36m""Répertoire $(OBJ_DIR) supprimé.""\033[0m"

fclean:		clean
			$(RM) $(NAME)
			@make clean -C lib/minilibx-linux
			@echo "\033[36m""Exécutable $(NAME) supprimé.""\033[0m"

re:			fclean all

.PHONY: all clean fclean re
