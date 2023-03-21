/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_forms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:48:44 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/21 12:23:19 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ratio_rectangle(t_data img, int x, int y, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if ((i > x * 0.10 && i < x * 0.90) && (j > y * 0.10 && j < y * 0.90))
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

void	bresenham_surligner(t_data img, int x1, int y1, int r, int color)
{
	int	x;
	int	y;
	int	p;

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
}

void	triforce_maker(t_data img, int y1, int x, int y, int color)
{
	int	i;
	int	j;
	int	k;
	int	size;

	i = 0;
	size = y1 * 0.20;
	j = size;
	my_mlx_pixel_put(&img, x, y, color);
	while (j > 0)
	{
		while (i < size)
		{
			k = 0;
			while (k <= i * 0.75)
			{
				my_mlx_pixel_put(&img, x + k, y + i, color);
				my_mlx_pixel_put(&img, x - k, y + i, color);
				k++;
			}
			i++;
		}
		j--;
	}
}

void	triforce_surligner(t_data img, int y1, int x, int y, int color)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	size;

	i = 1;
	size = (y1 * 0.20) * 2;
	my_mlx_pixel_put(&img, x, y, color);
	while (i < size)
	{
		my_mlx_pixel_put(&img, x + (i * 0.75), y + i, color);
		my_mlx_pixel_put(&img, x - (i * 0.75), y + i, color);
		my_mlx_pixel_put(&img, x + (i * 0.75) + 1, y + i, color);
		my_mlx_pixel_put(&img, x - (i * 0.75) - 1, y + i, color);
		i++;
	}
	j = 0;
	while (j < i * 0.75)
	{
		my_mlx_pixel_put(&img, x + j, y + i, color);
		my_mlx_pixel_put(&img, x - j, y + i, color);
		my_mlx_pixel_put(&img, x + j, y + i - 1, color);
		my_mlx_pixel_put(&img, x - j, y + i - 1, color);
		j++;
	}
	k = 1;
	while (k < i / 2)
	{
		my_mlx_pixel_put(&img, x + (k * 0.75), y + i - k, color);
		my_mlx_pixel_put(&img, x - (k * 0.75), y + i - k, color);
		my_mlx_pixel_put(&img, x + (k * 0.75), y + i - k - 1, color);
		my_mlx_pixel_put(&img, x - (k * 0.75), y + i - k + 1, color);
		k++;
	}
	l = 0;
	while (l < i * 0.75)
	{
		my_mlx_pixel_put(&img, x - (j / 2) + l, y + k, color);
		my_mlx_pixel_put(&img, x - (j / 2) + l, y + k + 1, color);
		l++;
	}
}
