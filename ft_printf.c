/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 04:35:08 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/07/27 05:02:44 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char c, va_list args)
{
	if (c == 'c')
		return ft_putchar(va_arg(args, int));
	else if (c == 's')
		return ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		return ft_putptr((unsigned long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		return ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		return ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		return ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		return ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		return ft_putchar('%');
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += handle_format(format[++i], args);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
