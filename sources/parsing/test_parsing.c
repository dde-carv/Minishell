#include "minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

// Mock implementation of minis() and related structures for testing
t_global	*minis(void)
{
	static t_global		data;
	static t_minishell	ms;
	static t_hashmap	env;
	static t_hashmap	non_value_vars;

	if (!data.ms)
	{
		data.ms = &ms;
		data.input = NULL;
		data.env = &env;
		data.non_value_vars = &non_value_vars;
	}
	return (&data);
}

int	main(int ac, char **av, char **env)
{
	// Initialize minishell globals
	(void)av;
	(void)ac;
	set_env(env);
	while (1)
	{
		minis()->ms->line = readline("$ >");
		if (*(minis()->ms->line) != '\0')
			add_history(minis()->ms->line);

		// Test parse_input()
		ft_printf("=== Test parse_input ===\n");
		parse_input();
		t_input *current_input = minis()->input;
		if (current_input)
		{
			ft_printf("Parsed Commands:\n");
			while (current_input)
			{
				ft_printf("Command: %s, Argument: %s\n",
					current_input->cmd, current_input->arg);
				current_input = current_input->next;
			}
		}
		else
			ft_printf("Input line is empty.\n");

		// Reset input for the clean_content test
		ft_printf("\n=== Test clean_content ===\n");
		// Free previous input if needed (assuming free_t_input is the correct cleanup)
		/* if(minis()->input)
			free_t_input(minis()->input);
		minis()->input = NULL;

		// Set a new command line with some expansion and quotes to see transformation effect
		minis()->ms->line = "\"echo \"$_\"\"";
		// Parse the new input line before transforming it
		parse_input(); */

		ft_printf("Before clean_content:\n");
		current_input = minis()->input;
		while (current_input)
		{
			ft_printf("Command: %s, Argument: %s\n",
				current_input->cmd, current_input->arg);
			current_input = current_input->next;
		}

		// Call clean_content() to clean/transform the input string
		ft_printf("\nCalling clean_content...\n");
		clean_content();

		// Print the cleaned commands for verification
		ft_printf("\nAfter clean_content:\n");
		current_input = minis()->input;
		while (current_input)
		{
			ft_printf("Cleaned Command: %s, Cleaned Argument: %s\n",
				current_input->cmd, current_input->arg);
			current_input = current_input->next;
		}
		if (!ft_strcmp(minis()->ms->line, "exit") && (ft_strlen(minis()->ms->line)) == 4)
			break;
	}
	exit_minishell();
	return 0;
}
/* clear && cc -Wall -Wextra -Werror -lreadline -o test_parsing parsing.c \
args.c \
clean_content.c \
expantion.c \
redirects.c \
split.c \
test_parsing.c \
transform.c \
validation.c \
../hashmap/hashmap_create_table.c \
../hashmap/hashmap_handle_collision.c \
../hashmap/hashmap_free.c \
../hashmap/hashmap_search.c \
../hashmap/hashmap_delete.c \
../hashmap/hashmap_create_entry.c \
../hashmap/hash.c \
../hashmap/hashmap_insert.c \
./parsing_lst/ft_input_lstclear.c \
./parsing_lst/ft_input_lstadd_back.c \
./parsing_lst/ft_input_lstdelone.c \
./parsing_lst/ft_input_lstnew.c \
./parsing_lst/ft_input_lstsize.c \
./parsing_lst/ft_fd_add_back.c \
./parsing_lst/ft_fd_new.c \
../builtins/env.c \
../builtins/print_env.c \
../builtins/array_utils.c \
../builtins/set_sesh_vars.c \
../builtins/hashmap_to_array.c \
../minishell_utils/error.c \
../../libft/libft.a \
-I../../includes && valgrind --suppressions=../../readline.supp --show-leak-kinds=all --leak-check=full --track-origins=yes ./test_parsing && rm test_parsing*/
