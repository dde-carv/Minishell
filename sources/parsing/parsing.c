#include "../../includes/minishell.h"

void	cpy_input(t_entry *entry)
{
	t_input	*input;

	input = ft_input_lstnew(entry->key, entry->value);
	if (!input)
		exit(0);
	ft_input_lstadd_back(&minis()->input, input);
}

static char	*remove_spaces(char *str)
{
	int	start;
	int	end;

	end = ft_strlen(str) - 1;
	start = 0;
	while (end > start && str[end] == ' ')
		end--;
	return (ft_substr(str, start, end - start + 1));
}

/**
 * Extracts a command from the input starting at index *i.
 * Updates *i to the position after the command.
 */
static char	*extract_arg(const char *input, int *i)
{
	int		start;
	int		in_quotes;
	char	*arg;

	in_quotes = 0;
	while (input[*i] == ' ')
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
	if (start == *i)
		return (ft_strdup(""));
	arg = remove_spaces(ft_substr(input, start, *i - start));
	return (arg);
}
	
	/* // Remove surrounding quotes if present
	if ((arg[0] == '\'' && arg[ft_strlen(arg) - 1] == '\'') ||
		(arg[0] == '"' && arg[ft_strlen(arg) - 1] == '"'))
	{
		char *temp = ft_substr(arg, 1, ft_strlen(arg) - 2);
		free(arg);
		arg = temp;
	} */

/**
 * Extracts an argument from the input starting at index *i.
 * Updates *i to the position after the argument.
 */
static char *extract_cmd(char *input, int *i)
{
	char	*cmd;
	int		start;
	int		in_quotes;

	in_quotes = 0;
	// Skip leading spaces
	while (input[*i] == ' ')
		(*i)++;
	start = *i;
	// Extract until pipe outside quotes
	while (input[*i] && (input[*i] != ' ' || in_quotes) \
		&& (input[*i] != '|' || in_quotes))
	{
		if ((input[*i] == '\'' || input[*i] == '"') && !in_quotes)
			in_quotes = input[*i];
		else if (in_quotes == input[*i])
			in_quotes = 0;
		(*i)++;
	}
	if (start == *i)
		return (ft_strdup(""));
	cmd = ft_substr(input, start, *i - start);
	return (cmd);
}

void	parse_input(void)
{
	int		i;
	char	*cmd;
	char	*arg;
	t_entry	*entry;

	i = 0;
	while (minis()->ms->line[i])
	{
		cmd = extract_cmd(minis()->ms->line, &i);
		arg = extract_arg(minis()->ms->line, &i);
		entry = hash_action(minis()->table, (t_entry){cmd, arg, NULL}, ENTER);
		if (!entry)
			exit(191);
		if (minis()->ms->line[i] == '|')
			i++;
		cpy_input(entry);
		free(cmd);
		free(arg);
	}
}
