NAME	=	minishell

LIBFT		=	./libft/libft.a
INC			=	includes/
SRC_DIR		=	sources/
OBJ_DIR		=	objects/

CC		=	@cc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	@rm -f

BUILTINS_DIR	=	$(SRC_DIR)builtins/cd.c \
					$(SRC_DIR)builtins/env.c \
					$(SRC_DIR)builtins/pwd.c \
					$(SRC_DIR)builtins/unset.c \
					$(SRC_DIR)builtins/print_env.c \
					$(SRC_DIR)builtins/array_utils.c \
					$(SRC_DIR)builtins/echo.c

HASHMAP_DIR		=	$(SRC_DIR)hashmap/hash.c \
					$(SRC_DIR)hashmap/hashmap_create_entry.c \
					$(SRC_DIR)hashmap/hashmap_create_table.c \
					$(SRC_DIR)hashmap/hashmap_delete.c \
					$(SRC_DIR)hashmap/hashmap_free.c \
					$(SRC_DIR)hashmap/hashmap_handle_collision.c \
					$(SRC_DIR)hashmap/hashmap_insert.c \
					$(SRC_DIR)hashmap/hashmap_print_table.c \
					$(SRC_DIR)hashmap/hashmap_search.c

MSL_UTILS_DIR	=	$(SRC_DIR)minishell_utils/data.c \
					$(SRC_DIR)minishell_utils/error.c

SYS_MSL_DIR		=	$(SRC_DIR)system/main.c \
					$(SRC_DIR)system/prompt.c


SRCS	=	$(SYS_MSL_DIR) $(MSL_UTILS_DIR) $(HASHMAP_DIR) $(BUILTINS_DIR)

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
