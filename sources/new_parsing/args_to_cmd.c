/* #include "minishell.h"

char	*new_cut(char **s, int init, int end)
{
	char	*new_string;
	int		i;
	int		j;

	if (init >= end)
		return (free(*s), ft_strdup(""));
	new_string = ft_calloc(sizeof(char *), ft_strlen(*s));
	if (!new_string)
		return (NULL);
	i = -1;
	j = -1;
	while ((*s)[++i])
	{
		if (i < init || i >= end)
			new_string[++j] = (*s)[i];
	}
	free(*s);
	return (new_string);
}

void	args_to_cmd(void)
{
	int	i;

	i = -1;
	while (minis()->input->args[++i])
		ft_input_lstadd_back(&minis()->input, ft_input_lstnew("", minis()->input->args[i]));
	free_array((void **)minis()->input->args);
	redirects_parsing();
}
 */