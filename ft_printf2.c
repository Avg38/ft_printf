/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:09 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/06 17:00:53 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long long addr, size_t *len)
{
	char	byte[16];
	int		i;

	if (!addr)
	{
		ft_print_str("(nil)", len);
		return ;
	}
	else
	{
		i = -1;
		while (++i < 16)
		{
			byte[i] = "0123456789abcdef"[addr % 16];
			addr /= 16;
		}
		i = 15;
		ft_print_str("0x", len);
		while (byte[i] == '0')
			i--;
		while (i >= 0)
		{
			ft_print_char(byte[i], len);
			i--;
		}
	}
}

void	ft_print_nbr(int nb, size_t *len)
{
	if (nb == -2147483648)
		ft_print_str("-2147483648", len);
	else if (nb < 0)
	{
		ft_print_char(45, len);
		ft_print_nbr(-nb, len);
	}
	else if (nb > 9)
	{
		ft_print_nbr(nb / 10, len);
		ft_print_nbr(nb % 10, len);
	}
	else
		ft_print_char(nb % 10 + 48, len);
}

void	ft_print_hexa(unsigned int nb, char *base, size_t *len)
{
	if (nb > 15)
		ft_print_hexa(nb / 16, base, len);
	ft_print_char(base[nb % 16], len);
}

void	ft_print_unsigned(unsigned int nb, size_t *len)
{
	if (nb > 9)
	{
		ft_print_unsigned(nb / 10, len);
		ft_print_unsigned(nb % 10, len);
	}
	else
		ft_print_char(nb % 10 + 48, len);
}
