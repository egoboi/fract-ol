/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:06:09 by fbrisson          #+#    #+#             */
/*   Updated: 2023/06/13 16:51:42 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render(t_fract *fdata)
{
	int	x;
	int	y;
	int iter;
	t_complex c;

	mlx_clear_window(fdata->mlx_ptr, fdata->mlx_window);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		//printf("%d\n", y);
		while (++x < WINDOW_WIDTH)
		{
			// c.r = (x / WINDOW_WIDTH) * fdata->width + (fdata->center_r - fdata->width / 2);
			// c.i = (y / WINDOW_HEIGHT) * fdata->height + (fdata->center_i - fdata->height / 2);
			// printf("c_r : %f  ",c.r);
			// printf("c_i : %f\n",c.i);
			// printf("%d\n", x);
			iter = mandelbrot_algo(x, y, fdata);
			// my_mlx_pixel_put(&fdata->img, c.r, c.i, iter);
			my_mlx_pixel_put(&fdata->img, x, y, 1 - ((double)iter * 100 / (double)fdata->max_iter) * 100000000);
		}
	}
	mlx_put_image_to_window(fdata->mlx_ptr, fdata->mlx_window, fdata->img.img, 0, 0);
}
