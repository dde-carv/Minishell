
#include "minishell.h"

void	ft_pwd(void)
{
	char	*cwd;

	minis()->error_status = 0;
	cwd = getcwd(NULL, 0);
	if(cwd)
		ft_printf("%s\n", cwd);
	else
		error_mess("pwd", NO_FILE_OR_DIR, 1);
	free(cwd);
}
