/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 04:35:08 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/08/04 20:20:58 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_putchar('%'));
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
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int ret_ft, ret_std;

	printf("\n===== TESTES ft_printf x printf =====\n\n");

	// Teste de char
	ret_ft = ft_printf("FT:   Char: [%c]\n", 'A');
	ret_std = printf("STD:  Char: [%c]\n", 'A');
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de string
	ret_ft = ft_printf("FT:   String: [%s]\n", "Hello");
	ret_std = printf("STD:  String: [%s]\n", "Hello");
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste string NULL
	ret_ft = ft_printf("FT:   Null string: [%s]\n", NULL);
	ret_std = printf("STD:  Null string: [%s]\n", (char *)NULL);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de int (%d e %i)
	ret_ft = ft_printf("FT:   Int d: [%d], Int i: [%i]\n", 42, -42);
	ret_std = printf("STD:  Int d: [%d], Int i: [%i]\n", 42, -42);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de INT_MIN e INT_MAX
	ret_ft = ft_printf("FT:   INT_MIN: [%d], INT_MAX: [%d]\n", INT_MIN, INT_MAX);
	ret_std = printf("STD:  INT_MIN: [%d], INT_MAX: [%d]\n", INT_MIN, INT_MAX);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de unsigned int
	ret_ft = ft_printf("FT:   Unsigned: [%u]\n", UINT_MAX);
	ret_std = printf("STD:  Unsigned: [%u]\n", UINT_MAX);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de hex (x e X)
	ret_ft = ft_printf("FT:   Hex lower: [%x], upper: [%X]\n", 255, 255);
	ret_std = printf("STD:  Hex lower: [%x], upper: [%X]\n", 255, 255);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de hex com valores negativos (tratados como unsigned)
	ret_ft = ft_printf("FT:   Hex neg: [%x]\n", (unsigned int)-42);
	ret_std = printf("STD:  Hex neg: [%x]\n", (unsigned int)-42);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de ponteiros
	ret_ft = ft_printf("FT:   Pointer: [%p]\n", &ret_ft);
	ret_std = printf("STD:  Pointer: [%p]\n", &ret_ft);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de ponteiro NULL
	ret_ft = ft_printf("FT:   Pointer NULL: [%p]\n", (void *)0);
	ret_std = printf("STD:  Pointer NULL: [%p]\n", (void *)0);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de porcentagem %%
	ret_ft = ft_printf("FT:   Percent: [%%]\n");
	ret_std = printf("STD:  Percent: [%%]\n");
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	// Teste de mix geral
	ret_ft = ft_printf("FT:   Mix: %c %s %d %u %x %X %p %%\n",
					   'Z', "Teste", -123, 123u, 0x42, 0x42, &ret_ft);
	ret_std = printf("STD:  Mix: %c %s %d %u %x %X %p %%\n",
					 'Z', "Teste", -123, 123u, 0x42, 0x42, &ret_ft);
	printf("Return FT: %d | STD: %d\n\n", ret_ft, ret_std);

	return 0;
}


