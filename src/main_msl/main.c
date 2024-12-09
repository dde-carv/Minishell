/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:07 by dde-carv          #+#    #+#             */
/*   Updated: 2024/12/09 11:10:33 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
//function to get the prompt using env variable
static char	*ft_getprompt(char **env)
{
	int		i;
	char	**promp;
	char	*last;

	i = 0;
	promp = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
			promp = ft_split(env[i], '/');
		i++;
	}
	i = 0;
	while (promp[i])
		i++;
	last = ft_strdup(promp[i - 1]);
	i = 0;
	while (promp[i])
	{
		free(promp[i]);
		i++;
	}
	free(promp);
	return (last);
}

/* static void	start_pipex(char *line, char **env) //function to initialize pipex
{
	char	**line_split;
	int		i;

	i = 0;
	line_split = ft_split(line, ' ');
} */

int	main(int ac, char **av, char **env)
{
	(void)av;
	char	*line;
	char	*promp;

	if (ac == 1)
	{
		while (1)
		{
			promp = ft_getprompt(env);
			ft_printf("%s > ", promp);
			line = get_next_line(0);
			if (!ft_strncmp(line, "exit", 4) && (ft_strlen(line) - 1) == 4)
			{
				write(1, "exit\n", 5);
				break;
			}
			// start_minishell(line, env); //function to initialize minishell(not implemented)
			ft_printf("%s", line);
			free (promp);
			free (line);
		}
		free(line);
		free(promp);
	}
	return (0);
}
