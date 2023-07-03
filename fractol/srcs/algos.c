/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:53:12 by lgolino           #+#    #+#             */
/*   Updated: 2023/07/03 15:54:18 by lgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	put_pixel_image(int x, int y, t_fractal *d, int color)
{
	int	pos;

	pos = (y * HW) + x;
	d->addr[pos] = color;
}

void	mandelbrot(t_fractal *mBrot)
{
	mBrot->x = -1;
	while (++mBrot->x < HW)
	{
		mBrot->y = -1;
		while (++mBrot->y < HW)
		{
			mand_plane(mBrot);
			while (mBrot->zx * mBrot->zx + mBrot->zy * mBrot->zy < 4
				&& mBrot->i < mBrot->max_i)
			{
				mBrot->tmp = mBrot->zx * mBrot->zx - mBrot->zy * mBrot->zy
					+ mBrot->cx;
				mBrot->zy = 2 * mBrot->zx * mBrot->zy + mBrot->cy;
				mBrot->zx = mBrot->tmp;
				mBrot->i++;
			}
			put_pixel_image(mBrot->x, mBrot->y, mBrot, mBrot->color);
		}
	}
	mlx_look(mBrot);
}

void	julia(t_fractal *julia)
{
	julia->x = -1;
	while (++julia->x < HW)
	{
		julia->y = -1;
		while (++julia->y < HW)
		{
			julia_plane(julia);
			while (julia->zx * julia->zx + julia->zy * julia->zy < 4
				&& julia->i < julia->max_i)
			{
				julia->tmp = julia->zx;
				julia->zx = julia->zx * julia->zx - julia->zy * julia->zy
					+ julia->cx;
				julia->zy = 2 * julia->tmp * julia->zy + julia->cy;
				julia->i++;
			}
			put_pixel_image(julia->x, julia->y, julia, julia->color);
		}
	}
	mlx_look(julia);
}

void	douady(t_fractal *dou)
{
	dou->x = -1;
	while (++dou->x < HW)
	{
		dou->y = -1;
		while (++dou->y < HW)
		{
			dou_plane(dou);
			while (dou->zx * dou->zx + dou->zy * dou->zy < 4
				&& dou->i < dou->max_i)
			{
				dou->tmp = dou->zx;
				dou->zx = dou->zx * dou->zx - dou->zy * dou->zy + dou->cx;
				dou->zy = 2 * dou->tmp * dou->zy + dou->cy;
				dou->i++;
			}
			put_pixel_image(dou->x, dou->y, dou, dou->color);
		}
	}
	mlx_look(dou);
}
