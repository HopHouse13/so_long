# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 17:02:37 by ubuntu            #+#    #+#              #
#    Updated: 2024/11/25 19:42:10 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# # Répertoires
# SRCS_DIR	= srcs
# OBJ_DIR 	= obj_so_long

# # Commandes
# CC			= cc
# RM			= rm -rf
# CFLAGS		= -Wall -Wextra -Werror -ggdb -I$(SRCS_DIR)

# # Nom de l'exécutable
# NAME		= so_long

# # Recherche récursive des fichiers .c dans srcs/
# SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.c")

# # Conversion des fichiers .c en .o dans obj_so_long/
# OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

# # Règle par défaut
# all:		$(NAME)

# # Compilation finale de l'exécutable
# $(NAME):	$(OBJS)
# 			$(CC) $(OBJS) -o $(NAME)
# 			@echo "Compilation de $(NAME) terminée !"

# # Compilation des fichiers .c en .o dans obj_so_long/
# # Crée les sous-dossiers nécessaires
# $(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
# 			@mkdir -p $(@D)
# 			$(CC) $(CFLAGS) -c $< -o $@

# # Nettoyage des fichiers objets
# clean:
# 			$(RM) $(OBJ_DIR)
# 			@echo "Répertoire $(OBJ_DIR) supprimé."

# # Nettoyage complet (exécutable et objets)
# fclean:		clean
# 			$(RM) $(NAME)
# 			@echo "Exécutable $(NAME) supprimé."

# # Recompilation complète
# re:			fclean all

# .PHONY: clean fclean re all







SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.c")


SRCS_DIR	= srcs
OBJ_DIR 	= obj_so_long
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -ggdb -c -I$(SRCS_DIR)
NAME		= so_long

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
