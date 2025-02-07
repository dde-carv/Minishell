#include "minishell.h"

int		array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i + 1])
		i++;
	return (i);
}

void	ft_strjoin_to_array(char *str, char **array)
{
	int		i;
	char	*tmp;

	i = 0;
	while (array[i])
	{
		tmp = ft_strjoin(str, array[i]);
		free(array[i]);
		array[i] = tmp;
		i++;
	}
}

void	print_array_fd(char **array, int fd)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putendl_fd(array[i], fd);
		i++;
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**split_into2(char *arg, char c)
{
	char	**splited;
	char	*c_p;

	splited = (char **)malloc(3 * sizeof(char *));
	c_p = ft_strchr(arg, c);
	splited[0] = ft_substr(arg, 0, (c_p - arg));
	splited[1] = ft_substr((c_p + 1), 0, (ft_strlen(c_p)));
	splited[2] = NULL;
	return(splited);
}
