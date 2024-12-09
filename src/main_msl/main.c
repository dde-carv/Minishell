/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:07 by dde-carv          #+#    #+#             */
/*   Updated: 2024/12/09 14:36:23 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
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

/* static void	start_minishell(char *line, char **env) //function to initialize pipex
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
	char	*full_promp;

	if (ac == 1)
	{
		while (1)
		{
			ft_printf("\033[1;92m➜  \033[1;96m");
			promp = ft_getprompt(env);
			full_promp = ft_strjoin(promp, "\033[1;33m $ \033[0m");
			free(promp);
			line = readline(full_promp);
			if (!line)
				break;
			if (*line)
				add_history(line);
			//line = get_next_line(0);
			if (!ft_strncmp(line, "exit", 4) && (ft_strlen(line)) == 4)
			{
				write(1, "exit\n", 5);
				//ft_exitminishell(...); //function to exit minishell(not implemented)
				break;
			}
			// start_minishell(line, env); //function to initialize minishell(not implemented)
			ft_printf("%s\n", line);
			free (full_promp);
			//free (promp);
			free (line);
		}
		free(line);
		free (full_promp);
		//free (promp);
	}
	return (0);
}
