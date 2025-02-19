#include "minishell.h"

void	transform_str(void)
{
	if (!is_valid())
	{
		ft_lstclear(&minis()->input->cmd, ft_lstdelone);
		printf("Not valid!\n");
		return ;
	}
	clean_content();
	if (minis()->input->cmd && *minis()->input->cmd)
		execute();/*skip_to_exec_cmd*/
}
	/* if (ft_strchr(minis()->input->cmd, '='))
		bool skip_to_exec_cmd = true; */
