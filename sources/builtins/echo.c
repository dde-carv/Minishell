
#include "minishell.h"

/* static size_t	full_length(char **array, int *i)
{
	int j;
	size_t	total;

	j = *i;
	total = 0;
	while (array[j])
	{
		total += ft_strlen(array[j]);
		j++;
	}
	return (total);
}

static char	*full_str(char **args, int *i)
{
	int		j;
	char	*new_str;

	j = *i;
	new_str = malloc(full_length(args, i) + array_len(args) + 1);
	new_str[0] = '\0';
	while (args && args[j])
	{
		if (args[j + 1])
			tmp = ft_strjoin(args[j], " ");
		else
			tmp = strdup(args[j]);
		if (!new_str)
			new_str = ft_strcpy(new_str, tmp);
		else
			new_str = ft_strjoin(new_str, tmp);
		free_pointer(tmp);
		ft_strcat(new_str, args[j]);
		if (args[j + 1])
			ft_strcat(new_str, " ");
		j++;
	}
	return (new_str);
}

void	ft_echo(char **args, int fd)
{
	int		i;
	int		new_flag;
	char	*str;

	i = 0;
	new_flag = 1;
	if (!ft_strcmp(args[i], "-n"))
	{
		new_flag = 0;
		i++;
	}
	str = full_str(args, &i);
	if (new_flag)
		ft_putendl_fd(str, fd);
	else
		ft_putstr_fd(str, fd);
	free_pointer(str);
	minis()->error_status = 0;
} */

static int	verify_new(char **args, int *i)
{
	int		j;
	int		new_flag;

	j = 0;
	new_flag = 1;
	/* if (!*args[*i] || !args[*i][j])
		return (new_flag); */
	while (args[*i] && !ft_strncmp(args[*i], "-n", 2))
	{
		j = 1;
		while(args[*i][j] && args[*i][j] == 'n')
		{
			j++;
		}
		if (!args[*i][j])
			new_flag = 0;
		else
			return(new_flag);
		(*i)++;
	}
	return (new_flag);
}

void	ft_echo(char **args, int fd)
{
	int	i;
	int	new_flag;

	i = 0;
	/* if (!args[i] || !*args[i])
		return ; */
	new_flag = verify_new(args, &i);
	while (args && args[i])
	{
		if (args[i + 1])
		{
			//ft_printf("%s ", args[i]);
			ft_putstr_fd(args[i], fd);
			ft_putstr_fd(" ", fd);
		}
		else
			ft_putstr_fd(args[i], fd);
		i++;
	}
	if (new_flag)
	ft_putstr_fd("\n", fd);
	minis()->error_status = 0;
}
