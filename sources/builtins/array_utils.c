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
