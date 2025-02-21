#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

#include "minishell.h"

void	load_signals(void);
void	sig_handler(int signum, siginfo_t *sig, void *s);
void	sig_handler_here(int signum, siginfo_t *sig, void *s);
#endif