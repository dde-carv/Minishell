# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 10:12:31 by dde-carv          #+#    #+#              #
#    Updated: 2025/01/14 18:07:17 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIBFT		=	./libft/libft.a
INC			=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/

CC		=	@cc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	@rm -f

HASHMAP			=	$(SRC_DIR)hashmap/hash.c \
					$(SRC_DIR)hashmap/hashmap_create_entry.c \
					$(SRC_DIR)hashmap/hashmap_create_table.c \
					$(SRC_DIR)hashmap/hashmap_delete.c \
					$(SRC_DIR)hashmap/hashmap_free.c \
					$(SRC_DIR)hashmap/hashmap_handle_collision.c \
					$(SRC_DIR)hashmap/hashmap_insert.c \
					$(SRC_DIR)hashmap/hashmap_print_table.c \
					$(SRC_DIR)hashmap/hashmap_search.c

MSL_UTILS_DIR	=	$(SRC_DIR)minishell_utils/env_dup.c \
					$(SRC_DIR)minishell_utils/env_create.c \
					$(SRC_DIR)minishell_utils/env_utils.c \
					$(SRC_DIR)minishell_utils/error.c \
					$(SRC_DIR)minishell_utils/data.c

MAIN_MSL_DIR	=	$(SRC_DIR)main_msl/main.c

SRCS	=	 $(MAIN_MSL_DIR) $(MSL_UTILS_DIR) $(HASHMAP)

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		@echo "\033[1;32mMake .o and executable.\033[0m"
		@$(CC) $(CFLAGS) -I$(INC) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
		@make -s -C ./libft

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@echo "\033[1;31mClean .o files.\033[0m"

fclean:		clean
		$(RM) $(NAME)
		@make -s fclean -C ./libft
		@echo "\033[1;31mClean executable/s.\033[0m"

re:		fclean all

.PHONY:		clean fclean re
