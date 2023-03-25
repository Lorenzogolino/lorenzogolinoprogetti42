/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgolino <lgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:55:54 by lgolino           #+#    #+#             */
/*   Updated: 2023/02/22 17:02:26 by lgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(int p);
int	ft_putnbr(int a);
int	ft_putstr(char *str);
int	ft_putnbr_base(unsigned int nb, int base, char *format);
int	ft_pointer(unsigned long nb);

#endif