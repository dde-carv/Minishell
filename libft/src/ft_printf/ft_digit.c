/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:45:43 by dde-carv          #+#    #+#             */
/*   Updated: 2024/07/09 11:30:09 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_print_num(int n)
{
	char	*s;
	int		len;

	ft_putnbr_fd(n, 1);
	s = ft_itoa(n);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_print_unsi(unsigned int n)
{
	char	*ptr;
	int		len;

	ptr = ft_itoa_base(n, 10, "0123456789");
	len = ft_print_str(ptr);
	free (ptr);
	return (len);
}

int	ft_print_ptr(void *n)
{
	char	*ptr;
	int		len;

	len = 0;
	if (n == 0)
		len = ft_print_str("(nil)");
	else
	{
		len = ft_print_str("0x");
		ptr = ft_itoa_base((long unsigned int)n, 16, "0123456789abcdef");
		len += ft_print_str(ptr);
		free (ptr);
	}
	return (len);
}

int	ft_print_hex(unsigned int n, char specifier)
{
	char	*ptr;
	int		len;

	len = 0;
	if (specifier == 'x')
		ptr = ft_itoa_base(n, 16, "0123456789abcdef");
	else
		ptr = ft_itoa_base(n, 16, "0123456789ABCDEF");
	len += ft_print_str(ptr);
	free (ptr);
	return (len);
}
