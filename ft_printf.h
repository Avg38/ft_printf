/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:17:59 by avialle-          #+#    #+#             */
/*   Updated: 2023/11/27 10:17:59 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_print_char(int c);
void	ft_print_nbr(int nb, char *base, int *len);
int		ft_print_ptr(void *str);
int		ft_print_str(char *str);
int		ft_strlen(char *str);
int		ft_printf(const char *str, ...);
void	ft_print_unsigned(unsigned int nb, int *len);
// int	main(void);

#endif
