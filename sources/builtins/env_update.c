
#include "minishell.h"

void	shlvl_update(void)
{
	int	n;
	char *nbr;
	char *tmp;

	tmp = ft_strdup(hashmap_search(minis()->env, "SHLVL"));
	hashmap_delete(minis()->env, "SHLVL");
	n = ft_atoi(tmp);
	n = n + 1;
	nbr = ft_itoa(n);
	insert_in_table("SHLVL", nbr, minis()->env);
	free(tmp);
	free(nbr);

}
