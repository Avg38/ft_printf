/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints    .c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:45:32 by avialle-          #+#    #+#             */
/*   Updated: 2023/11/29 16:45:32 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
	{
		ft_print_str("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (ft_strlen(str));
}

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
