/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:09 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/06 14:17:02 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_addr(unsigned long long addr)
{
	char	*base;
	char	stack[16];
	int		i;
	int		len;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		stack[i] = base[addr % 16];
		i++;
		addr /= 16;
	}
	i = 15;
	ft_print_char(48);
	ft_print_char('x');
	while (stack[i] == '0')
		i--;
	i++;
	len = i + 2;
	while (stack[--i] != '\0')
		ft_print_char(stack[i]);
	return (len);
}

int	ft_print_ptr(void *str)
{
	unsigned char	*addr;

	if (!str)
	{
		ft_print_str("(nil)");
		return (5);
	}
	addr = (unsigned char *)str;
	return (ft_print_addr((unsigned long long)&addr[0]));
}

void	ft_print_nbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 1);
		return ;
	}
	else if (nb < 0)
	{
		(*len)++;
		ft_print_unsigned(-nb, len);
	}
	else if (nb > 9)
	{
		ft_print_unsigned(nb / 10, len);
		ft_print_unsigned(nb % 10, len);
	}
	else
	{
		(*len)++;
		ft_print_char(nb % 10 + 48);
	}
}

void	ft_print_hexa(unsigned int nb, char *base, int *len)
{
	if (nb > 15)
		ft_print_hexa(nb / 16, base, len);
	(*len)++;
	ft_print_char(base[nb % 16]);
}

void	ft_print_unsigned(unsigned int nb, int *len)
{
	if (nb > 9)
	{
		ft_print_unsigned(nb / 10, len);
		ft_print_unsigned(nb % 10, len);
	}
	else
	{
		(*len)++;
		ft_print_char(nb % 10 + 48);
	}
}
