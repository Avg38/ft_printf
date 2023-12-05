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

#include "libftprintf.h"

static int	len_nbr(int nb, int len_base)
{
	int			len;
	long int	nb_tmp;

	len = 0;
	nb_tmp = (long int)nb;
	if (nb_tmp < 0)
	{
		len++;
		nb_tmp = -nb_tmp;
	}
	while (nb_tmp / len_base != 0)
	{
		len++;
		nb_tmp /= len_base;
	}
	len++;
	return (len);
}

static void	ft_putnbr_base(int nb, char *base, int len_base)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nb, base, len_base);
	}
	else if (nb > len_base)
	{
		ft_putnbr_base(nb / len_base, base, len_base);
		ft_putnbr_base(nb % len_base, base, len_base);
	}
	else
		ft_print_char(base[nb % len_base]);
}

int	ft_print_nbr(int nb, char *base)
{
	int	len_base;

	len_base = ft_strlen(base);
	ft_putnbr_base(nb, base, len_base);
	return (len_nbr(nb, len_base));
}

static int	len_var(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (c == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len = ft_print_nbr(va_arg(args, int), "0123456789");
	else if (c == 'u')
		len = ft_print_nbr(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		len += ft_print_nbr(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_print_nbr(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len += ft_print_char(37);
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
	char	c = '4';
	char	*str = "Hello World!";
	char	*ptr = "Hello World!";
	int		d = -2147483647;
	int		i = 2147483647;
	int		u = 54;
	int		x = 42;
	int		X = 42;

	ft_printf("ft_printf: %c\n", c);
	printf("printf: %c\n", c);
	ft_printf("ft_printf: %s\n", str);
	printf("printf: %s\n", str);
	ft_printf("ft_printf: %p\n", &ptr);
	printf("printf: %p\n", &ptr);
	ft_printf("ft_printf: %d\n", d);
	printf("printf: %d\n", d);
	ft_printf("ft_printf: %i\n", i);
	printf("printf: %i\n", i);
	ft_printf("ft_printf: %u\n", u);
	printf("printf: %u\n", u);
	ft_printf("ft_printf: %x\n", x);
	printf("printf: %x\n", x);
	ft_printf("ft_printf: %X\n", X);
	printf("printf: %X\n", X);
	ft_printf("ft_printf: %%\n");
	printf("printf: %%\n");


	
}
