/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:08:36 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/22 15:53:38 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_algo(int x, int y, t_data *data)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int			i;

	z = 
}
















	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			i = 0;
			while (z < 2 && i < 100)
			{
				if (i == 100)
					my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
				z = z * z + c;
				i++;
			}
			x++;
		}
		y++;
	}
}
