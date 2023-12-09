/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:36:42 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/06 16:58:13 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_print_str(char *str, size_t *len)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		ft_print_char(str[i], len);
		i++;
	}
}

static void	len_var(va_list args, const char c, size_t *len)
{
	if (c == 'c')
		ft_print_char(va_arg(args, int), len);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), len);
	else if (c == 'p')
		ft_print_ptr(va_arg(args, unsigned long long), len);
	else if (c == 'd' || c == 'i')
		ft_print_nbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_print_hexa(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	else if (c == '%')
		ft_print_char(37, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_var(args, str[i + 1], &len);
			i++;
		}
		else
			ft_print_char(str[i], &len);
		i++;
	}
	va_end(args);
	return ((int)len);
}
