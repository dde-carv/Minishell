/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:51 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:34:07 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_sig = 0;

void	load_signals(void)
{
	static struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = sig_handler;
	sigaction(SIGINT, &sig, NULL);
	if (minis()->signal == 1)
		signal(SIGQUIT, SIG_IGN);
	if (minis()->signal == 2)
	{
		sig.sa_sigaction = sig_handler_here;
		sigaction(SIGINT, &sig, NULL);
		signal(SIGQUIT, SIG_IGN);
	}
	if (minis()->signal == 3)
	{
		sig.sa_sigaction = sig_handler_pipe;
		sigaction(SIGINT, &sig, NULL);
		sigaction(SIGQUIT, &sig, NULL);
	}
}

void	sig_handler(int signum, siginfo_t *sig, void *s)
{
	(void)s;
	(void)sig;
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
		minis()->signal = 1;
	}
	if (signum == SIGQUIT)
		return ;
}

void	sig_handler_here(int signum, siginfo_t *sig, void *s)
{
	(void)s;
	(void)sig;
	if (signum == SIGINT)
	{
		g_sig = 1;
		rl_done = 1;
	}
	if (signum == SIGQUIT)
		return ;
}

void	sig_handler_pipe(int signum, siginfo_t *sig, void *s)
{
	(void)s;
	(void)sig;
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		minis()->error_status = 130;
	}
	if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
		minis()->error_status = 131;
	}
}
