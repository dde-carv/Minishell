/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:22:41 by dde-carv          #+#    #+#             */
/*   Updated: 2025/02/04 10:59:00 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_print_format(char specifier, va_list *ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(*ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(*ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_num(va_arg(*ap, int));
	else if (specifier == 'u')
		count += ft_print_unsi(va_arg(*ap, unsigned int));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(*ap, void *));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hex(va_arg(*ap, unsigned int), specifier);
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		len;

	len = 0;
	count = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (str[len] != '\0')
	{
		if (str[len] == '%')
		{
			count += ft_print_format(str[len + 1], &ap);
			len++;
		}
		else
			count += write(1, &str[len], 1);
		len++;
	}
	va_end(ap);
	return (count);
}
