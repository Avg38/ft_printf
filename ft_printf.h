/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:17:59 by avialle-          #+#    #+#             */
/*   Updated: 2023/12/06 16:01:10 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

void	ft_print_char(int c, size_t *len);
void	ft_print_str(char *str, size_t *len);
void	ft_print_ptr(unsigned long long addr, size_t *len);
void	ft_print_nbr(int nb, size_t *len);
void	ft_print_hexa(unsigned int nb, char *base, size_t *len);
void	ft_print_unsigned(unsigned int nb, size_t *len);
int		ft_printf(const char *str, ...);

#endif
