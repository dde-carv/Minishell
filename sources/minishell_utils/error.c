
#include "minishell.h"

void	free_env(void)
{
	t_env	*temp;
	t_env	*temp2;

	if (minis()->my_env->var_n)
		free(minis()->my_env->var_n);
	if (minis()->my_env->var_v)
		free(minis()->my_env->var_v);
	temp = minis()->my_env->next;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		if (temp2->var_n)
			free(temp2->var_n);
		if (temp2->var_v)
			free(temp2->var_v);
		free(temp2);
	}
	minis()->my_env->next = NULL;
}

void	exit_minishell(int flag)
{
	free_env();
	if (minis()->ms->line)
		free(minis()->ms->line);
	if (minis()->my_env)
		free(minis()->my_env);
	if (minis()->ms)
		free(minis()->ms);
	if (minis()->hash)
		free(minis()->hash);
	exit(flag);
}

void	error_mag(int flag)
{
	if (flag == MALL_ERROR)
		ft_printf("MALLOC failed........");
	exit_minishell(flag);
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
