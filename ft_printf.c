/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:36:42 by avialle-          #+#    #+#             */
/*   Updated: 2023/11/29 14:36:42 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_var(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (c == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		len = ft_print_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_print_nbr(va_arg(args, int), "0123456789", &len);
	else if (c == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), &len);
	else if (c == 'x')
		ft_print_nbr(va_arg(args, unsigned int), "0123456789abcdef", &len);
	else if (c == 'X')
		ft_print_nbr(va_arg(args, unsigned int), "0123456789ABCDEF", &len);
	else if (c == '%')
		len = ft_print_char(37);
	printf("\n%d\n", len);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += len_var(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_print_char(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	char	c = 'c';
	char	*str = NULL;
	char	*ptr = NULL;
	unsigned int	d = 2147483699;
	int		i = 2147483647;
	unsigned int	u = 2147483699;
	int		x = 42;
	int		X = 42;

	// printf("%s\n", str);
	ft_printf("ft_printf:\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n\n", c, str, ptr, d, i, u, x, X);
	printf("printf:\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", c, str, ptr, d, i, u, x, X);
}