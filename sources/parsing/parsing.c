#include "../../includes/minishell.h"

void	input_to_lst(char *cmd, char *arg)
{
	t_input *new_input;
	t_input *current;

	new_input = malloc(sizeof(t_input));
	if (!new_input)
		exit(1);
	new_input->cmd = ft_strdup(cmd);
	new_input->arg = ft_strdup(arg);
	if (!new_input->cmd || !new_input->arg)
	{
		free(new_input->cmd);
		free(new_input->arg);
		free(new_input);
		exit(1);
	}
	new_input->next = NULL;
	if (minis()->input == NULL)
		minis()->input = new_input;
	else
	{
		current = minis()->input;
		while (current->next)
			current = current->next;
		current->next = new_input;
	}
}
/**
 * Extracts a command from the input starting at index *i.
 * Updates *i to the position after the command.
 */
static char	*extract_arg(char *input, int *i)
{
	char	*arg;
	int	start;
	int	in_quotes;

	in_quotes = 0;
	while (input[*i] == ' ')
		(*i)++;
	start = *i;
	if (input[*i] == '|' || input[*i] == '\0')
		return (ft_strdup(""));
	// Extract until space or pipe outside quotes
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
	arg = ft_substr(input, start, *i - start);
	
	/* // Remove surrounding quotes if present
	if ((arg[0] == '\'' && arg[ft_strlen(arg) - 1] == '\'') ||
		(arg[0] == '"' && arg[ft_strlen(arg) - 1] == '"'))
	{
		char *temp = ft_substr(arg, 1, ft_strlen(arg) - 2);
		free(arg);
		arg = temp;
	} */
	return (arg);
}
/**
 * Extracts an argument from the input starting at index *i.
 * Updates *i to the position after the argument.
 */
static char *extract_cmd(char *input, int *i)
{
	char	*cmd;
	int	start;
	int	in_quotes;

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
	int	i;
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
			exit(EXIT_FAILURE);
		if (minis()->ms->line[i] == '|')
			i++;
		input_to_lst(cmd, arg);
		free(cmd);
		free(arg);
	}
}
