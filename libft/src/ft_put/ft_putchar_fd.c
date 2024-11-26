/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:17:30 by dde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 15:28:28 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//Outputs the character ’c’ to the given file descriptor.

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
