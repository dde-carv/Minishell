/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:18:36 by dde-carv          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:37 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_str(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

static int	get_argc(char **argv)
{
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	return (argc);
}

void	ft_exit(char **args)
{
	int		len;
	char	*full_mess;

	len = get_argc(args);
	ft_printf("exit\n");
	if (len == 0)
		exit_minishell();
	if (len == 1)
	{
		if (!is_str(args[0]))
		{
			full_mess = ft_strjoin_var(2, "exit: ", args[0]);
			error_mess(full_mess, NUM_ARG_REQUIRED, 2);
			free_pointer(full_mess);
			exit_minishell();
		}
		minis()->error_status = ft_atoi(args[0]) % 256;
		exit_minishell();
	}
	error_mess("exit", TOO_MANY_ARGS, 1);
}

/*
!	ERROR STATUS CODES

?	1. Success and Generic Error Codes

*	Exit Code	Meaning
!!		0	Success (command completed without errors)
!!		1	General error (catch-all for unknown issues)

?	2.	Common Bash-Reserved Exit Codes
?	Bash reserves some specific exit codes for particular situations:

*	Exit Code	Meaning
!!		2	Incorrect usage of a built-in command or syntax error
!!		126	Command found but not executable
!!		127	Command not found (e.g., typo or missing binary)
!!		128	Invalid argument to exit
!!		128+N	Command terminated by signal N (e.g., 130 means Ctrl+C
!!			killed it, since signal 2 = SIGINT)
!!		130	Script terminated by Ctrl+C (SIGINT)
!!		137	Process killed by SIGKILL (e.g., kill -9 <pid>)
!!		143	SIGTERM (15)	Terminated gracefully (kill <pid>)
!!		255	Exit status out of range (Bash allows 0-255)
 */
