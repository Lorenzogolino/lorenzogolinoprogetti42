
#include "../incl/fractal.h"

void	str_put(t_fractal *d)
{
	mlx_string_put(d->mlx, d->win, 720, 200,
		YELLOW, "KEYBOARD SHORCUTS:");
	mlx_string_put(d->mlx, d->win, 720, 250,
		YELLOW, "      CLOSE THE WINDOW: >>>>> X/ESC");
	mlx_string_put(d->mlx, d->win, 720, 300,
		YELLOW, "      CHANGE COLOR SHADE: >>>>> SHIFT");
	mlx_string_put(d->mlx, d->win, 720, 350,
		YELLOW, "      MOVE FRACTAL: >>>>> ARROWS");
	mlx_string_put(d->mlx, d->win, 720, 400,
		YELLOW, "      ZOOM/UNZOOM >>>>> PLUS/MINUS");
	mlx_string_put(d->mlx, d->win, 720, 450,
		YELLOW, "      CHANGE TO JULIA >>>>> J");
	mlx_string_put(d->mlx, d->win, 720, 500,
		YELLOW, "      CHANGE TO MANDELBROT: >>>>> M");
	mlx_string_put(d->mlx, d->win, 720, 550,
		YELLOW, "      CHANGE TO DOUADY: >>>>> D");
	mlx_string_put(d->mlx, d->win, 720, 600,
		YELLOW, "MOUSE INTERATION:");
	mlx_string_put(d->mlx, d->win, 720, 650,
		YELLOW, "      ZOOM/UNZOOM: >>>>> MOUSE ROLL");
	mlx_string_put(d->mlx, d->win, 720, 700,
		YELLOW, "      ZOOM & MOVE: >>>>> LEFT MOUSE CLICK");
}

int	ft_close(t_fractal *d)
{
	write(1, "\nWELCOME BACK TO REALITY SON\n", 29);
	mlx_destroy_window(d->mlx, d->win);
	free(d);
	exit(0);
}

void	dou_plane(t_fractal *dou)
{
	dou->color = dou->i * BLACK + dou->shade;
	dou->i = 0;
	dou->zx = (dou->x / (HW / (dou->x_end - dou->x_start))
			+ dou->x_start) * dou->zoom + dou->x_shift;
	dou->zy = (dou->y / (HW / (dou->y_end - dou->y_start))
			+ dou->y_start) * dou->zoom + dou->y_shift;
	dou->cx = -0.12565651;
	dou->cy = 0.65720;
}

void	julia_plane(t_fractal *julia)
{
	julia->color = julia->i * VIOLET + julia->shade;
	julia->i = 0;
	julia->zx = (julia->x / (HW / (julia->x_end - julia->x_start))
			+ julia->x_start) * julia->zoom + julia->x_shift;
	julia->zy = (julia->y / (HW / (julia->y_end - julia->y_start))
			+ julia->y_start) * julia->zoom + julia->y_shift;
	julia->cx = -0.74543;
	julia->cy = 0.11301;
}

void	mand_plane(t_fractal *mBrot)
{
	mBrot->color = mBrot->i * BLUE + mBrot->shade;
	mBrot->i = 0;
	mBrot->cx = (mBrot->x / (HW / (mBrot->x_end - mBrot->x_start))
			+ mBrot->x_start) * mBrot->zoom + mBrot->x_shift;
	mBrot->cy = (mBrot->y / (HW / (mBrot->y_end - mBrot->y_start))
			+ mBrot->y_start) * mBrot->zoom + mBrot->y_shift;
	mBrot->zx = 0;
	mBrot->zy = 0;
}
