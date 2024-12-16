/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:07 by dde-carv          #+#    #+#             */
/*   Updated: 2024/12/16 12:04:17 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//function to get the prompt using env variable
static char	*ft_getprompt(void)
{
	int		i;
	char	**promp;
	char	*cwd;
	char	*last;

	i = 0;
	promp = NULL;
	cwd = NULL;
	cwd = getcwd(cwd, 0);
	promp = ft_split(cwd, '/');
	free(cwd);
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
	((void)av, (void)env);
	char	*line;
	char	*promp;
	char	*full_promp;

	if (ac == 1)
	{
		while (1)
		{
			ft_printf("\033[1;92m➜  \033[1;96m");
			promp = ft_getprompt();
			full_promp = ft_strjoin(promp, "\033[1;33m $ \033[0m");
			free(promp);
			line = readline(full_promp);
			free(full_promp);
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
			free (line);
			//free (promp);
		}
		rl_clear_history();
		free(line);
		//free (full_promp);
		//free (promp);
	}
	return (0);
}
