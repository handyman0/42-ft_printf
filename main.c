/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 05:28:14 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/08/07 20:05:28 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	// (Teste de hex (x e X))
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
