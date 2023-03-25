/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgolino <lgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:22:12 by lgolino           #+#    #+#             */
/*   Updated: 2023/02/23 11:46:27 by lgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long nb)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_pointer(nb);
	return (i);
}

int	check_type(char c, va_list d)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(d, int));
	else if (c == 's')
		count += ft_putstr(va_arg(d, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(d, int));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(d, unsigned long));
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(d, unsigned int), 10, "0123456789");
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(d, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(d, unsigned int), 16, "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	d;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(d, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += check_type(s[i + 1], d);
			i++;
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(d);
	return (count);
}

// int	main(int argc, char const *argv[])
// {
// 	int r = 65;
// 	int *p = &r;
// 	ft_printf("%c %s %i %p %X\n", 'g', "bro", 78, p, 15);
// 	return (0);
// }
