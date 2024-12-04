# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 10:12:31 by dde-carv          #+#    #+#              #
#    Updated: 2024/12/04 21:56:03 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIBFT		=	./libft/libft.a
INC			=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/

CC		=	@cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	@rm -f

#MSL_UTILS_DIR	=	$(SRC_DIR)minishell_utils/

MAIN_MSL_DIR	=	$(SRC_DIR)main_msl/main.c

SRCS	=	 $(MAIN_MSL_DIR)
#$(MSL_UTILS_DIR)
OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		@echo "\33[1;32mMake .o and executable.\033[0m"
		@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
		@make -s -C ./libft

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@echo "\33[1;31mClean .o files.\033[0m"

fclean:		clean
		$(RM) $(NAME)
		@make -s fclean -C ./libft
		@echo "\33[1;31mClean executable/s.\033[0m"

re:		fclean all

.PHONY:		clean fclean re
