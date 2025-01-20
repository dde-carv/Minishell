#include "../../includes/minishell.h"

void	parse_input(t_hashmap *table, const char *input,)
{
	size_t	index;
	t_entry	*entry;
	char	*command;
	char	*arg;

	index = 0;
	while (input[index])
	{
		while (input[index] == ' ')
			index++;
		command = extract_command(input, &index);
		if (!command)
			return ;
		arg = extract_arg(input, &index);
		if (!arg)
		{
			free (command);
			return ;
		}
		entry = hashmap_search(table, command);
		if (input[index])
			index++;
		copy(m, entry);
		free (command);
		free (arg);
	}
}