
#include "minishell.h"

static int	is_str(char *arg)
{
	int i;

	i = 0;
	while(arg[i])
	{
		if(!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	check_arg(char *arg)
{
	if (!arg)
		return ;
	if (!is_str(arg))
	{
		minis()->error_status = 2;
		error_mess("exit", NUM_ARG_REQUIRED, 2);
		return ;
	}
	minis()->error_status = ft_atoi(arg);
	return ;
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
	int	len;

	len = get_argc(args);
	ft_printf("exit\n");
	if (len > 1)
	{
		error_mess("exit", TOO_MANY_ARGS, 2);
		return ;
	}
	check_arg(args[0]);
	exit_minishell();
}
