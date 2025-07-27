#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	total;

	ft_printf(NULL);
	total = ft_printf("Oiiiii %c %s %s %d %i %d %x %X %x %X %p %p 100%% %u %u\n", 'a', "Paula", NULL,  INT_MAX, INT_MIN, 0, 255, 255, -255, -255, &total, (void *)0, UINT_MAX, 0);
	printf("%d\n", total);
	total = printf("Oiiiii %c %s %s %d %i %d %x %X %x %X %p %p 100%% %u %u\n", 'a', "Paula", NULL, INT_MAX, INT_MIN, 0, 255, 255, -255, -255, &total, (void *)0, UINT_MAX, 0);
	printf("%d\n", total);
	ft_printf_bonus("YOUR FUNCTION: %.1d\n", 1);
	printf("ORIGINAL: %.1d\n", 1);
	return (0);
}
