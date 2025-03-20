
#include "minishell.h"

static char	*ft_get_last(char *path)
{
	int		i;
	char	*last;
	char	**prompt;

	if (!*path || !path)
		return (NULL);
	if (!ft_strcmp(path, "/"))
		return (last = ft_strdup("/"));
	prompt = ft_split(path, '/');
	i = -1;
	while (prompt[++i]);
	last = ft_strdup(prompt[i - 1]);
	free_array((void **)prompt);
	return (last);
}

//Function to get the prompt via cwd (current working directory)
static char	*ft_getprompt(void)
{
	char	*cwd;
	char	*last;

	cwd = getcwd(NULL, 0);
	if (!ft_strcmp(cwd, "/"))
	{
		free(cwd);
		return (last = ft_strdup("/"));
	}
	last = ft_get_last(cwd);
	free(cwd);
	return (last);
}

void	set_input(void)
{
	char	*last;
	char	*last_HOME;
	char	*full_promp;

	last_HOME = NULL;
	last = ft_getprompt();
	if (hashmap_search(minis()->env, "HOME"))
		last_HOME = ft_get_last(hashmap_search(minis()->env, "HOME"));
	if (!ft_strcmp(last, last_HOME))
	{
		free(last);
		last = ft_strdup("~");
	}
	full_promp = ft_strjoin_var(5, BOLD_CYAN, last, BOLD_YELLOW, " $ ", RESET_COLOR);
	minis()->ms->promp = ft_strdup(full_promp);
	free(last);
	free(last_HOME);
	minis()->ms->line = readline(minis()->ms->promp);
	free(full_promp);
	free(minis()->ms->promp);
	if ((minis()->ms->line) == NULL)
	{
		ft_printf("exit\n");
		exit_minishell();
	}
	if (*(minis()->ms->line) != '\0')
		add_history(minis()->ms->line);
}
