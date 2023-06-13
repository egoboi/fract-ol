/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:08:36 by fbrisson          #+#    #+#             */
/*   Updated: 2023/06/13 16:45:56 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_algo(double x, double y, t_fract *fdata)
{
	t_complex	z;
	t_complex	c;
	double	tmp;
	int	iter;

	c.r = (x / WINDOW_WIDTH) * fdata->width + (fdata->center_r - fdata->width / 2);
	c.i = (y / WINDOW_HEIGHT) * fdata->height + (fdata->center_i - fdata->height / 2);
	// printf("c_r : %f  ",c.r);
	// printf("c_i : %f\n",c.i);
	z.i = 0.00;
	z.r = 0.00;
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < fdata->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		iter++;
	}
	return (iter);
	// if (iter == fdata->max_iter)
	// {
	// 	my_mlx_pixel_put(&fdata->img, x, y, 0x000000);
	// }
	// else
	// 	my_mlx_pixel_put(&fdata->img, x, y, 1 - ((double)iter * 100 / (double)fdata->max_iter) * 10000);
	// // printf("iter : %d ", iter);
	// // my_mlx_pixel_put(&fdata->img, x, y, iter + 100);
}
