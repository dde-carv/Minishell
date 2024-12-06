/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:07 by dde-carv          #+#    #+#             */
/*   Updated: 2024/12/06 12:01:42 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*ft_getprompt(char **env) //function to get the prompt using env variable
{
	int		i;
	char	**promp;

	i = 0;
	promp = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			promp = ft_split(env[i], '/');
			break ;
		}
		i++;
	}
	i = 0;
	while (promp[i])
		i++;
	return (promp[i - 1]);
}

static void	start_pipex(char *line, char **env) //function to initialize pipex
{
	char	**cmd
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	char	*line;

	if (ac == 1)
	{
		while (1)
		{
			ft_printf("%s > ", ft_getprompt(env));
			line = get_next_line(0);
			if (!ft_strncmp(line, "exit", 4) && (ft_strlen(line) - 1) == 4)
			{
				write(1, "exit\n", 5);
				break;
			}
			start_minishell(line, env); //function to initialize minishell(not implemented)
			ft_printf("%s", line);
			free (line);

		}
		//free(line);
	}
	return (0);
}
