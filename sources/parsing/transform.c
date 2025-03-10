#include "minishell.h"

void	transform_str(void)
{
	if (!is_valid())
	{
		ft_input_lstclear(&minis()->input);
		printf("Not valid!\n");
		return ;
	}
	clean_content();
	/* if (minis()->input->cmd && *minis()->input->cmd)
		execute(); */
}
