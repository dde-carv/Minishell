/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:39:26 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 09:48:02 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

/* int	main(void)
{
	minis()->ms->line = "infile ls | pwd";
	minis()->table = create_table(100);
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
	return 0;
} */

/* clear && cc -Wall -Wextra -Werror -o test_parsing parsing.c \
test_parsing.c \
../builtins/array_utils.c \
../hashmap/hashmap_create_table.c \
../hashmap/hashmap_handle_collision.c \
../hashmap/hashmap_free.c \
../hashmap/hashmap_search.c \
../hashmap/hashmap_create_entry.c \
../hashmap/hash.c \
../hashmap/hashmap_insert.c \
./parsing_lst/ft_input_lstadd_back.c \
./parsing_lst/ft_input_lstdelone.c \
./parsing_lst/ft_input_lstnew.c \
../../libft/libft.a \
-I../../includes && ./test_parsing && rm test_parsing*/
