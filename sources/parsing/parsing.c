#include "../../includes/minishell.h"

void	cp_entry(t_entry *entry)
{

	minis()->input->cmd = cmd_to_lst(entry->key, entry->value);
	if (!cmd)
		exit(0);
	ft_lstadd_back(cmd->arg, new);
}
static char	*extract_arg(char *input, int *i)
{
	char	*arg;
	int	start;
	int	in_quotes;

	in_quotes = 0;
	while (input[*i] = ' ')
		(*i)++;
	start = *i;
	while (input[*i] && (input[*i] != '|' || in_quotes))
	{
		if ((input[*i] == '\'' || input[*i] == '"') && !in_quotes)
			in_quotes = input[*i];
		else if (in_quotes == input[*i])
			in_quotes = 0;
		(*i)++;
	}
	if (start = *i)
		return (ft_strdup(""));
	arg = ft_substr(input, start, *i - start);
	return (arg);
}

static char *extract_cmd(char *input, int *i)
{
	char	*cmd;
	int	start;
	int	in_quotes;

	in_quotes = 0;
	while (input[*i] = ' ')
		(*i)++;
	start = *i;
	while (input[*i] && (input[*i] != ' ' || in_quotes) \
		&& (input[*i] != '|' || in_quotes))
	{
		if ((input[*i] == '\'' || input[*i] == '"') && !in_quotes)
			in_quotes = input[*i];
		else if (in_quotes == input[*i])
			in_quotes = 0;
		(*i)++;
	}
	if (start = *i)
		return (ft_strdup(""));
	cmd = ft_substr(input, start, *i - start);
	return (cmd);
}


/* char	parse_input(t_hashmap *table, const char *input,)
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
} */