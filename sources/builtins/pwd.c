
#include "minishell.h"

void	ft_pwd(void)
{
	char	*cwd;

	minis()->error_status = 0;
	cwd = getcwd(NULL, 0);
	if(!cwd)
		return (error_mess("pwd", NO_FILE_OR_DIR, 1), (void)cwd);
	else
		ft_putendl_fd(cwd, minis()->input->l_write);
	free(cwd);
}
