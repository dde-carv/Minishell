/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:47:34 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:26:42 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Erases  the  data  in the n bytes of the memory starting
// at the location pointed to by s, by writing zeros.

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
