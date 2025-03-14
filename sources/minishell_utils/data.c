#include "minishell.h"

t_pipe	*pipex(void)
{
	static t_pipe	pipex;

	return (&pipex);
}

t_global	*minis(void)
{
	static t_global		data;
	static t_minishell	ms;
	static t_hashmap	env;
	static t_hashmap	non_value_vars;
	static t_input		input;

	if (!data.ms)
	{
		data.ms = &ms;
		data.input = &input;
		data.env = &env;
		data.non_value_vars = &non_value_vars;
	}
	return (&data);
}