/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:08:36 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/28 15:54:17 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_algo(int x, int y, t_fract *fdata)
{
	t_complex	z;
	t_complex	c;
	double	tmp;
	int	iter;
	//int	colors[] = {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF, 0x0000FF, 0xFF00FF, 0xFFFFFF};

	c.r = (x / fdata->zoom) + fdata->x_min;
	c.i = (y / fdata->zoom) + fdata->y_min;
	z.r = 0.00;
	z.i = 0.00;
	iter = 0;
	while (z.r * z.r - z.i * z.i < 4 && iter < fdata->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		iter++;
	}
	if (iter == fdata->max_iter)
		my_mlx_pixel_put(fdata->img, x, y, 0x000000);
	else
		my_mlx_pixel_put(fdata->img, x, y, 1 - ((double)iter / (double)fdata->max_iter) * 999999);
}

void	mandelbrot_drawer(int x, int y, t_fract *fdata)
{
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mandelbrot_algo(x, y, fdata);	
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdata->mlx_ptr, fdata->mlx_window, fdata->img->img, 0, 0);
}

