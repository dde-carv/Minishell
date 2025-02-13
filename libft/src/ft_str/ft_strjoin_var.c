/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:54:11 by dde-carv          #+#    #+#             */
/*   Updated: 2025/02/13 16:34:34 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin_var(unsigned int arg_n, ...)
{
	char			*arg_buff;
	char			*tmp;
	char			*result;
	va_list			arg_list;
	unsigned int	i;

	va_start(arg_list, arg_n);
	i = 0;
	result = NULL;
	while (i < arg_n)
	{
		arg_buff = va_arg(arg_list, char *);
		if (!result)
			result = ft_strdup(arg_buff);
		else
		{
			tmp = ft_strjoin(result, arg_buff);
			free(result);
			result = tmp;
		}
		i++;
	}
	va_end(arg_list);
	return (result);
}
