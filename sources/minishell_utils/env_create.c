
#include "minishell.h"

void	env_create(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	create_var("SHLVL", "1", NO_MALL);
	create_var("PWD", pwd, NY_MALL);
	create_var("_", "/usr/bin/env", NO_MALL);
	//free(pwd);
}
