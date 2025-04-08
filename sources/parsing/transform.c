/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:25:44 by luiribei          #+#    #+#             */
/*   Updated: 2025/04/08 10:27:09 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	transform_input(void)
{
	if (!is_valid())
	{
		ft_input_lstclear(&minis()->input);
		return ;
	}
	clean_content();
	if (minis()->input)
		execute();
}
