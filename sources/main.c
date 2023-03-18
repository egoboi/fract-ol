/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:15:37 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/18 15:18:09 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ratio_rectangle(t_data img, int y, int x, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((j > x * 0.15 && j < x * 0.85) && (i > y * 0.15 && i < y * 0.85))
				my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		i++;
	}
}

void	bresenham_circle_draw(t_data img, int xctr, int yctr, int x, int y, int color)
{
	my_mlx_pixel_put(&img, xctr + x, yctr + y, color);
	my_mlx_pixel_put(&img, xctr - x, yctr + y, color);
	my_mlx_pixel_put(&img, xctr + x, yctr - y, color);
	my_mlx_pixel_put(&img, xctr - x, yctr - y, color);
	my_mlx_pixel_put(&img, xctr + y, yctr + x, color);
	my_mlx_pixel_put(&img, xctr - y, yctr + x, color);
	my_mlx_pixel_put(&img, xctr + y, yctr - x, color);
	my_mlx_pixel_put(&img, xctr - y, yctr - x, color);
}

void	bresenham_circle(t_data img, int x1, int y1, int r, int color)
{
	int	x;
	int	y;
	int	p;

	while (r > 0)
	{
		x = 0;
		y = r;
		p = 1 - r;
		bresenham_circle_draw(img, x1, y1, x, y, color);
		while (x < y && r > 0)
		{
			x++;
			if (p < 0)
				p += 2 * x + 1;
			else
			{
				y--;
				p += 2 * (x - y) + 1;
			}
			bresenham_circle_draw(img, x1, y1, x, y, color);
		}
		r--;
	}
}

void	triforce_maker(t_data img, int y, int x, int color)
{
	int	i;
	int	j;
	float	klow;
	float	khigh;

	i = 0;
	klow = 0.40;
	khigh = 0.60;
	while (i < x)
	{
		j = 0;
		while (j < i)
		{
			if ((klow == 0.50) || (khigh == 0.50))
				break ;
			if ((j > x * klow && j < x * khigh) && (i > y * 0.40 && i < y * 0.60))
			{
				my_mlx_pixel_put(&img, i, j, color);
				klow += 0.01;
				khigh -= 0.01;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data		img;
	int	y_res;
	int	x_res;

	y_res = 1920;
	x_res = 1080;
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, y_res, x_res, "Hello world MAGGLE");
	img.img = mlx_new_image(mlx, y_res, x_res);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	ratio_rectangle(img, y_res, x_res, 0x00FA8072);

	bresenham_circle(img, y_res / 2, x_res / 2, 325, 0x00D8BFD8);

	//triforce_maker(img, y_res / 2, x_res / 2, 0x00DAA520);

	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
