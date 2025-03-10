#ifdef __APPLE__
int rl_replace_line(const char *text, int clear_undo)
{
	(void)text;
	(void)clear_undo;
	return 0;
}
#endif

#include "minishell.h"

//extern int rl_replace_line(const char *text, int clear_undo);

void	load_signals(void)
{
	static struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = sig_handler;
	sigaction(SIGINT, &sig, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_handler(int signum, siginfo_t *sig, void *s)
{
	(void)s;
	(void)sig;
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		ft_printf("\n");
		rl_on_new_line();
		rl_redisplay();
		minis()->signal = 1;
		minis()->error_status = 130;
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
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		minis()->signal = 1;
		minis()->error_status = 130;
	}
	if (signum == SIGQUIT)
		return ;
}
