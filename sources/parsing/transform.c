/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:38:51 by luiribei          #+#    #+#             */
/*   Updated: 2025/02/19 10:00:12 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
