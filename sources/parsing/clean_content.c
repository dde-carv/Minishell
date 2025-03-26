#include "minishell.h"

void	update_quote_state(char c, char *in_quotes)
{
	if ((c == '"' || c == '\'') && !(*in_quotes))
		*in_quotes = c;
	else if (c == *in_quotes)
		*in_quotes = 0;
}

static void	take_spaces(char **s)
{
	int	i;

	i = ft_strlen(*s) - 1;
	if (i == -1)
		return ;
	while (i && (*s)[i] == ' ')
		(*s)[i--] = 0;
}

void	take_quotes(char **str)
{
	char	old_in_quotes;
	char	in_quotes;
	char	*s;
	int		i;
	int		j;

	s = *str;
	i = 0;
	j = 0;
	in_quotes = 0;
	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\''))
		{
			old_in_quotes = in_quotes;
			update_quote_state((*str)[i], &in_quotes);
			if (old_in_quotes == in_quotes)
				(*str)[j++] = s[i];
		}
		else
			(*str)[j++] = s[i];
		i++;
	}
	(*str)[j++] = '\0';
}

static void	take_expantions(t_input **lst)
{
	bool	f;
	int		i;

	i = 0;
	f = needs_split((*lst)->cmd);
	take_quotes(&(*lst)->cmd);
	while (is_expantion((*lst)->cmd))
		(*lst)->cmd = sub_expantion((*lst)->cmd, get_value((*lst)->cmd));
	while (is_expantion((*lst)->arg))
		(*lst)->arg = sub_expantion((*lst)->arg, get_value((*lst)->arg));
	if (f && *(*lst)->cmd)
		args(lst);
	else if ((*lst)->arg)
		(*lst)->args = split_value((*lst)->arg);
	//print_array_fd((*lst)->args, 1);
	while ((*lst)->args && (*lst)->args[i])
	{
		take_quotes(&(*lst)->args[i]);
		take_spaces(&(*lst)->args[i]);
		i++;
	}
}

void	clean_content(void)
{
	t_input	*lst;

	lst = minis()->input;
	while (lst)
	{
		// Debug: before handling redirection
        /* printf("[DEBUG] Before redirection parsing: cmd = \"%s\", arg = \"%s\"\n",
            lst->cmd ? lst->cmd : "NULL", lst->arg ? lst->arg : "NULL"); */
		if (has_redirection(lst->cmd) || has_redirection(lst->arg))
		{
            parse_redirects(&lst);
            // Debug: after redirection processing
            /* printf("[DEBUG] After redirection parsing: cmd = \"%s\", arg = \"%s\"\n",
                lst->cmd ? lst->cmd : "NULL", lst->arg ? lst->arg : "NULL"); */
        }
		expantions(&lst->cmd);
		expantions(&lst->arg);
		take_expantions(&lst);
		// Debug: after expansion/taking tokens from args
        /* if (lst->args)
        {
            int i = 0;
            printf("[DEBUG] lst->args after expansion: ");
            while (lst->args[i])
            {
                printf("\"%s\" ", lst->args[i]);
                i++;
            }
            printf("\n");
        } */
        lst = lst->next;
	}
}
