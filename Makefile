# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 10:17:48 by dde-carv          #+#    #+#              #
#    Updated: 2025/04/08 11:57:58 by dde-carv         ###   ########.fr        #
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

BUILTINS_DIR	=	$(SRC_DIR)builtins/env.c \
					$(SRC_DIR)builtins/cd_utils.c \
					$(SRC_DIR)builtins/print_env.c \
					$(SRC_DIR)builtins/env_update.c \
					$(SRC_DIR)builtins/array_utils.c \
					$(SRC_DIR)builtins/export_utils.c \
					$(SRC_DIR)builtins/hashmap_to_array.c \
					$(SRC_DIR)builtins/cd.c \
					$(SRC_DIR)builtins/pwd.c \
					$(SRC_DIR)builtins/echo.c \
					$(SRC_DIR)builtins/exit.c \
					$(SRC_DIR)builtins/unset.c \
					$(SRC_DIR)builtins/export.c \
					$(SRC_DIR)builtins/quick_sort.c \

EXEC_DIR		=	$(SRC_DIR)exec/executer.c \
					$(SRC_DIR)exec/fds.c \
					$(SRC_DIR)exec/pipes/exit_pipex.c \
					$(SRC_DIR)exec/pipes/fd_close.c \
					$(SRC_DIR)exec/pipes/fd_close_1.c \
					$(SRC_DIR)exec/pipes/fd_open.c \
					$(SRC_DIR)exec/pipes/here_doc.c \
					$(SRC_DIR)exec/pipes/path_utils.c \
					$(SRC_DIR)exec/pipes/pipex_utils.c \
					$(SRC_DIR)exec/pipes/pipex_utils_1.c \
					$(SRC_DIR)exec/pipes/pipex.c \

#					$(SRC_DIR)exec/pipes/family.c \

HASHMAP_DIR		=	$(SRC_DIR)hashmap/hash.c \
					$(SRC_DIR)hashmap/hashmap_free.c \
					$(SRC_DIR)hashmap/hashmap_insert.c \
					$(SRC_DIR)hashmap/hashmap_search.c \
					$(SRC_DIR)hashmap/hashmap_delete.c \
					$(SRC_DIR)hashmap/hashmap_print_table.c \
					$(SRC_DIR)hashmap/hashmap_create_entry.c \
					$(SRC_DIR)hashmap/hashmap_create_table.c \
					$(SRC_DIR)hashmap/hashmap_handle_collision.c

MSL_UTILS_DIR	=	$(SRC_DIR)minishell_utils/data.c \
					$(SRC_DIR)minishell_utils/free.c \
					$(SRC_DIR)minishell_utils/error.c

SYS_MSL_DIR		=	$(SRC_DIR)system/main.c \
					$(SRC_DIR)system/prompt.c

PARSING_DIR		=	$(SRC_DIR)parsing/args.c \
					$(SRC_DIR)parsing/split.c \
					$(SRC_DIR)parsing/parsing.c \
					$(SRC_DIR)parsing/get_value.c \
					$(SRC_DIR)parsing/expantion.c \
					$(SRC_DIR)parsing/redirects.c \
					$(SRC_DIR)parsing/redirects_utils.c \
					$(SRC_DIR)parsing/transform.c \
					$(SRC_DIR)parsing/bools.c \
					$(SRC_DIR)parsing/clean_content.c \
					$(SRC_DIR)parsing/parsing_lst/ft_fd_new.c \
					$(SRC_DIR)parsing/parsing_lst/ft_fd_del.c \
					$(SRC_DIR)parsing/parsing_lst/ft_fd_add_back.c \
					$(SRC_DIR)parsing/parsing_lst/ft_input_lstnew.c \
					$(SRC_DIR)parsing/parsing_lst/ft_input_lstsize.c \
					$(SRC_DIR)parsing/parsing_lst/ft_input_lstclear.c \
					$(SRC_DIR)parsing/parsing_lst/ft_input_lstdelone.c \
					$(SRC_DIR)parsing/parsing_lst/ft_input_lstadd_back.c



SIGNALS_DIR		=	$(SRC_DIR)signals/signals.c

SRCS	=	$(SYS_MSL_DIR) $(MSL_UTILS_DIR) $(HASHMAP_DIR) $(BUILTINS_DIR) $(PARSING_DIR) $(EXEC_DIR) $(SIGNALS_DIR)

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
