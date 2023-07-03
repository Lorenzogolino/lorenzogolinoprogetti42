/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:53:24 by lgolino           #+#    #+#             */
/*   Updated: 2023/07/03 15:54:38 by lgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	mouse_hook(int button, int x, int y, t_fractal *d)
{
	d->x = x;
	d->y = y;
	if (button == MOUSEUP)
		d->zoom *= 1.5;
	else if (button == MOUSEDOWN)
		d->zoom /= 1.5;
	else if (button == MOUSELEFT)
	{
		d->zoom *= 0.9;
		d->x_shift = (d->x / (HW / (d->x_end - d->x_start))
				+ d->x_start) * d->zoom + d->x_shift;
		d->y_shift = (d->y / (HW / (d->y_end - d->y_start))
				+ d->y_start) * d->zoom + d->y_shift;
	}
	which_fract(d);
	return (0);
}

void	mlx_look(t_fractal *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	str_put(d);
	mlx_key_hook(d->win, ft_key_press, d);
	mlx_hook(d->win, 17, 1L << 0, ft_close, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_loop(d->mlx);
	free(d);
}

int	ft_key_press3(int keycode, t_fractal *d)
{
	if (keycode == KEY_ESC || keycode == KEY_X)
	{
		write(1, "\nWELCOME BACK TO REALITY SON.\n", 30);
		mlx_destroy_window(d->mlx, d->win);
		free(d);
		exit(0);
	}
	else if (keycode == KEY_SHIFT_L || keycode == KEY_SHIFT_R)
		d->shade -= 4000;
	else if (keycode == KEY_MINUS)
		d->zoom += 0.02;
	else if (keycode == KEY_PLUS)
		d->zoom -= 0.02;
	which_fract(d);
	return (0);
}

int	ft_key_press2(int keycode, t_fractal *d)
{
	if (keycode == KEY_M)
	{
		d->name = "Mandelbrot";
		which_fract(d);
	}
	else if (keycode == KEY_J)
	{
		d->name = "Julia";
		which_fract(d);
	}
	else if (keycode == KEY_D)
	{
		d->name = "Douady";
		which_fract(d);
	}
	else
		ft_key_press3(keycode, d);
	return (0);
}

int	ft_key_press(int keycode, t_fractal *d)
{
	if (keycode == KEY_LEFT)
	{
		d->x_shift -= 0.04;
		which_fract(d);
	}
	else if (keycode == KEY_RIGHT)
	{
		d->x_shift += 0.04;
		which_fract(d);
	}
	else if (keycode == KEY_DOWN)
	{
		d->y_shift += 0.04;
		which_fract(d);
	}
	else if (keycode == KEY_UP)
	{
		d->y_shift -= 0.04;
		which_fract(d);
	}
	else
		ft_key_press2(keycode, d);
	return (0);
}
