/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:53:32 by lgolino           #+#    #+#             */
/*   Updated: 2023/07/03 15:53:43 by lgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

t_fractal	*id(char *s, t_fractal *d)
{
	d->max_i = 50;
	d->name = s;
	d->zoom = 1;
	d->x_shift = 0;
	d->y_shift = 0;
	d->shade = 0;
	d->x_start = -2.0;
	d->x_end = 2.0;
	d->y_start = -2.0;
	d->y_end = 2.0;
	return (d);
}

void	description(char *av[])
{
	if (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "Julia")
		|| !ft_strcmp(av[1], "Douady"))
	{
		write(1, "KEYBOARD SHORCUTS:\n", 20);
		write(1, "\tCLOSE THE WINDOW:\tX/ESC\n", 25);
		write(1, "\tCHANGE COLOR SHADE:\tSHIFT\n", 27);
		write(1, "\tMOVE FRACTAL:\t\t", 16);
		write(1, "ARROW-LEFT/ARROW-RIGHT/ARROW-UP/ARROW-DOWN\n", 43);
		write(1, "\tZOOM/UNZOOM:\t\tPLUS/MINUS\n", 26);
		write(1, "\tCHANGE TO JULIA:\tJ\n", 20);
		write(1, "\tCHANGE TO MANDELBROT:\tM\n", 25);
		write(1, "\tCHANGE TO DOUADY:\tD\n", 21);
		write(1, "MOUSE INTERATION:\n", 18);
		write(1, "\tZOOM/UNZOOM:\t\tMOUSE ROLL\n", 26);
		write(1, "\tZOOM & MOVE:\t\tLEFT MOUSE CLICK\n", 32);
	}
}

void	which_fract(t_fractal *d)
{
	if (ft_strcmp(d->name, "Mandelbrot") && ft_strcmp(d->name, "Julia")
		&& ft_strcmp(d->name, "Douady"))
	{
		write(2, "USAGE: ./fractal", 16);
		write(2, "\tMandelbrot\tJulia\tDouady\n", 25);
		exit(0);
	}
	if (ft_strcmp(d->name, "Mandelbrot") == 0)
		mandelbrot(d);
	else if (ft_strcmp(d->name, "Julia") == 0)
		julia(d);
	else if (ft_strcmp(d->name, "Douady") == 0)
		douady(d);
}

int	main(int ac, char **av)
{
	t_fractal	*d;

	if (ac == 2)
	{
		d = (t_fractal *)malloc(sizeof(t_fractal));
		description(av);
		d->mlx = mlx_init();
		d->win = mlx_new_window(d->mlx, HW, HW, "FRACT'OL");
		d->img = mlx_new_image(d->mlx, HW, HW);
		d->addr = (int *)mlx_get_data_addr(d->img, &d->bits_per_pixel,
				&d->line_length, &d->endian);
		id(av[1], d);
		which_fract(d);
	}
	else
	{
		write(2, "USAGE: ./fractal", 16);
		write(2, "\tMandelbrot\tJulia\tDouady\n", 25);
	}
	return (0);
}
