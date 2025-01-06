# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 10:12:31 by dde-carv          #+#    #+#              #
#    Updated: 2024/12/31 11:35:43 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIBFT		=	./libft/libft.a
INC			=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/

CC		=	@cc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	@rm -f

MSL_UTILS_DIR	=	$(SRC_DIR)minishell_utils/env_dup.c \
					$(SRC_DIR)minishell_utils/env_create.c \
					$(SRC_DIR)minishell_utils/env_utils.c \
					$(SRC_DIR)minishell_utils/error_mag.c

MAIN_MSL_DIR	=	$(SRC_DIR)main_msl/main.c

SRCS	=	 $(MAIN_MSL_DIR) $(MSL_UTILS_DIR)

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
