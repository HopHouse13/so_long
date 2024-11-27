# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 17:02:37 by ubuntu            #+#    #+#              #
#    Updated: 2024/11/27 01:43:54 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.c")
SRCS_DIR	= srcs
OBJ_DIR 	= obj_$(NAME)
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -ggdb -c -I$(SRCS_DIR)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)
			@echo "\033[32m""Compilation de $(NAME) est terminée !""\033[0m"
					
$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ_DIR)
			@echo "\033[36m""Répertoire $(OBJ_DIR) supprimé.""\033[0m"

fclean:		clean
			$(RM) $(NAME)
			@echo "\033[36m""Exécutable $(NAME) supprimé.""\033[0m"
								
re:			fclean all

.PHONY: clean fclean re bonus
