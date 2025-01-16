
#include "minishell.h"

void	exit_minishell(int flag)
{
	if (minis()->ms->line)
		free(minis()->ms->line);
	if (minis()->ms)
		free(minis()->ms);
	if (minis()->env)
	{
		free_table(minis()->env);
		free_table(minis()->sesion_vars);
	}
	exit(flag);
}

void	error_mess(char *input, char *message, int status)
{
	char	*error_out;

	error_out = ft_strjoin_var(
		7,
		BOLD_RED,
		"error: ",
		RED, input,
		": ", message,
		RESET_COLOR);
	ft_putendl_fd(error_out, 2);
	minis()->error_status = status;
	free(error_out);
}
