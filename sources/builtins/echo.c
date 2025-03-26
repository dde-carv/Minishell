
#include "minishell.h"

static size_t	full_length(char **array, int *i)
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
/* 		if (args[j + 1])
			tmp = ft_strjoin(args[j], " ");
		else
			tmp = strdup(args[j]);
		if (!new_str)
			new_str = ft_strcpy(new_str, tmp);
		else
			new_str = ft_strjoin(new_str, tmp);
		free_pointer(tmp); */
		ft_strcat(new_str, args[j]);
		if (args[j + 1])
			ft_strcat(new_str, " ");
		j++;
	}
	return (new_str);
}

void	ft_echo(char **args)
{
	int		i;
	int		new_flag;
	char	*str;

	i = 0;
	new_flag = 1;
	print_array_fd(args, 1);
	if (!ft_strcmp(args[i], "-n"))
	{
		new_flag = 0;
		i++;
	}
	str = full_str(args, &i);
	//ft_printf("%s\n", str);
	if (new_flag)
		ft_putendl_fd(str, minis()->input->l_write);
	else
		ft_putstr_fd(str, minis()->input->l_write);
	free_pointer(str);
	minis()->error_status = 0;
}
