/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:21:02 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 17:52:01 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	start_minishell(char **env)
{
	set_env(env);
	rl_catch_signals = 1;
	minis()->signal = 1;
	load_signals();
	minis()->error_status = 0;
}

static void	handle_sigint(void)
{
	if (minis()->signal != 0)
		minis()->signal = 0;
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac > 1)
		ft_putstr_fd("Too many arguments!\n", 2);
	start_minishell(env);
	while (1)
	{
		handle_sigint();
		set_input();
		if (!*minis()->ms->line)
			continue ;
		parse_input();
		transform_input();
		ft_input_lstclear(&minis()->input);
		free_pointer(minis()->ms->line);
	}
	exit_minishell();
	return (0);
}
