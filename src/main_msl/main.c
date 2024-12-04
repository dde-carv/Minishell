/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:07 by dde-carv          #+#    #+#             */
/*   Updated: 2024/12/04 22:20:27 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


int	main(int ac, char **av, char **envp)
{
	char	*line;

	if (ac == 1)
	{
		while (1)
		{
			ft_printf("minishell > ");
			line = get_next_line(0);
			if (!ft_strncmp(line, "exit", 4) && (ft_strlen(line) - 1) == 4)
			{
				write(1, "exit\n", 5);
				break;
			}
			//minishell fct
			ft_printf("%s", line);
			free (line);
		}
		free(line);
	}
	return (0);
}
