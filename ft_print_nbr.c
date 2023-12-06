/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:09 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/05 18:06:09 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	ft_putnbr_base(int nb, char *base, int len_base, int *len)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		(*len)++;
		ft_putnbr_base(-nb, base, len_base, len);
	}
	else if (nb > len_base)
	{
		ft_putnbr_base(nb / len_base, base, len_base, len);
		ft_putnbr_base(nb % len_base, base, len_base, len);
	}
	else
	{
		(*len)++;
		ft_print_char(base[nb % len_base]);
	}
}

void	ft_print_nbr(int nb, char *base, int *len)
{
	int	len_base;

	len_base = ft_strlen(base);
	ft_putnbr_base(nb, base, len_base, len);
	// return (len_nbr(nb, len_base));
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
		ft_print_char(nb % 10);
	}
}
