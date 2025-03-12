
#include "minishell.h"

void	exit_minishell(void)
{
	if (minis()->ms->line)
		free(minis()->ms->line);
	/* if (minis()->ms)
		free(minis()->ms); */
	if (minis()->input)
		ft_input_lstclear(&minis()->input);
		//free_t_input(minis()->input);
	/* if (minis()->input->args)
		free_args(minis()->input->args); */
	if (minis()->env)
	{
		free_table(minis()->env);
		free_table(minis()->non_value_vars);
		free_table(minis()->table);
	}
	exit(minis()->error_status);
}

void	error_mess(char *input, char *message, int status)
{
	char	*error_out;

	error_out = ft_strjoin_var(
		7,
		BOLD_RED,
		"minishell: ",
		RED, input,
		": ", message,
		RESET_COLOR);
	ft_putendl_fd(error_out, 2);
	minis()->error_status = status;
	free(error_out);
}
