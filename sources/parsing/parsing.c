#include "minishell.h"

static void	cpy_input(t_entry *entry)
{
	t_input	*input;

	input = ft_input_lstnew(entry->key, entry->value);
	if (!input)
		exit(0);
	ft_input_lstadd_back(&minis()->input, input);
}

static char	*remove_spaces(char *str)
{
	int		start;
	int		end;
	char	*new_str;

	end = ft_strlen(str) - 1;
	start = 0;
	while (end > start && str[end] == ' ')
		end--;
	new_str = ft_substr(str, start, end - start + 1);
	free(str);
	return (new_str);
}

static char	*extract_arg(const char *str, int *i)
{
	char	in_quotes;
	char	*arg;
	int		start;

	in_quotes = 0;
	while (str[*i] == ' ')
		(*i)++;
	start = *i;
	while (str[*i] && (str[*i] != '|' || in_quotes))
	{
		update_quote_state(str[*i], &in_quotes);
		(*i)++;
	}
	if (start == *i)
		return (ft_strdup(""));
	arg = remove_spaces(ft_substr(str, start, *i - start));
	return (arg);
}

static char	*extract_input(char *str, int *i)
{
	char	in_quotes;
	char	*cmd;
	int		start;

	in_quotes = 0;
	while (str[*i] == ' ')
		(*i)++;
	start = *i;
	while (str[*i] && (str[*i] != ' ' || in_quotes) \
		&& (str[*i] != '|' || in_quotes))
	{
		update_quote_state(str[*i], &in_quotes);
		(*i)++;
	}
	if (start == *i)
		return (ft_strdup(""));
	cmd = ft_substr(str, start, *i - start);
	return (cmd);
}

/* void	mark_pipes(char *str)
{
	int	i;
	int	s;

	s = 0;
	i = -1;
	while(str[++i])
	{
		if (str[i] == '"' || str[i] == '\'')
			s = str[i];
		if (!str && str[i] == '|')
			str[i] = 2;
	}
} */

void	parse_input(void)
{
	int		i;
	char	*cmd;
	char	*arg;
	t_entry	*entry;

	i = 0;
	/* mark_pipes(&minis()->ms->line[i]);
	minis()->input->args = ft_split(minis()->ms->line, ' '); */
	while (minis()->ms->line[i])
	{
		//? before "cmd = extract_input(minis()->ms->line, &i)" update the redirect type/file_name into the t_fd struct and then remove them from the line (ex: "< infile echo hi > outfile there" becomes "echo hi there");
		//parse_redirects(&minis()->input);
		cmd = extract_input(minis()->ms->line, &i);
		arg = extract_arg(minis()->ms->line, &i);
		entry = hash_action(minis()->table, (t_entry){cmd, arg, NULL}, ENTER);
		if (!entry)
			exit(0);
		if (minis()->ms->line[i] == '|')
			i++;
		cpy_input(entry);
		free_t_entry(entry);// ! Posible Invalid free because of parsing and expantions(in transform_str.c clean_content function)
		free(cmd);
		free(arg);
	}
	if (minis()->ms->line[i - 1] == '|')
		cpy_input(&(t_entry){"", "", NULL});
}
