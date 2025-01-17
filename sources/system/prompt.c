
#include "minishell.h"

//Function to get the prompt via cwd (current working directory)
static char	*ft_getprompt(void)
{
	int		i;
	char	**promp;
	char	*cwd;
	char	*last;

	i = 0;
	cwd = getcwd(NULL, 0);
	if (!ft_strcmp(cwd, "/"))
	{
		free(cwd);
		return (last = ft_strdup("/"));
	}
	promp = ft_split(cwd, '/');
	free(cwd);
	i = -1;
	while (promp[++i]);
	last = ft_strdup(promp[i - 1]);
	i = -1;
	while (promp[++i])
		free(promp[i]);
	free(promp);
	return (last);
}

void	set_input(void)
{
	char	*last;
	char	*full_promp;

	last = ft_getprompt();
	full_promp = ft_strjoin_var(5, BOLD_CYAN, last, BOLD_YELLOW, " $ ", RESET_COLOR);
	minis()->ms->promp = ft_strdup(full_promp);
	free(last);
	minis()->ms->line = readline(minis()->ms->promp);
	free(full_promp);
	free(minis()->ms->promp);
	if (minis()->ms->line)
		add_history(minis()->ms->line);
}
