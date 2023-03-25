/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfprova.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgolino <lgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:03:54 by lgolino           #+#    #+#             */
/*   Updated: 2023/02/23 10:52:48 by lgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int p)
{
	return (write(1, &p, 1));
}

int	ft_putnbr(int a)
{
	int	i;

	i = 0;
	if (a == -2147483648)
	{
		i += ft_putstr("-2");
		a = 147483648;
	}
	if (a < 0)
	{
		i += write(1, "-", 1);
		a = -a;
	}
	if (a > 9)
		i += ft_putnbr(a / 10);
	i += ft_putchar(a % 10 + 48);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned int nb, int base, char *format)
{
	int	i;

	i = 0;
	if (nb >= (unsigned int)base)
		i += ft_putnbr_base(nb / base, base, format);
	i += ft_putchar(format[nb % base]);
	return (i);
}

int	ft_pointer(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_pointer(nb / 16);
	i += ft_putchar("0123456789abcdef"[nb % 16]);
	return (i);
}
