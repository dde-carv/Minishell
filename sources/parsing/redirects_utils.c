#include "minishell.h"

/* This function splits a processed string into a command and its arguments.
It searches for the first space in the string and uses that as a delimiter.
If a space is found, the string is split: the part before the space becomes
the new command and the part after becomes the new argument.
If no space is found, the whole string becomes the command with an empty
argument.
Before updating, the function frees the original command and argument strings
held in the t_input structure. */
void	update_cmd_args(t_input **cmd, char *processed_str)
{
	char	*space_pos;

	space_pos = ft_strchr(processed_str, ' ');
	if (space_pos)
	{
		*space_pos = '\0';
		free((*cmd)->cmd);
		(*cmd)->cmd = ft_strdup(processed_str);
		free((*cmd)->arg);
		(*cmd)->arg = ft_strdup(space_pos + 1);
	}
	else
	{
		free((*cmd)->cmd);
		(*cmd)->cmd = ft_strdup(processed_str);
		free((*cmd)->arg);
		(*cmd)->arg = ft_strdup("");
	}
}

char	*remove_all_quotes(char *s)
{
	int		i;
	int		j;
	char	*result;

	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\'' && s[i] != '"')
			result[j++] = s[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}
