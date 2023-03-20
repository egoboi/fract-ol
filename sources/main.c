/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:15:37 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/20 18:46:43 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == 27)
		mlx_destroy_window(vars->mlx, vars->mlx_window);
	return (0);
}

int	main(void)
{
	t_data		img;
	t_vars		vars;
	int	x_res;
	int	y_res;
	int	triforce_color;

	x_res = 1920;
	y_res = 1080;
	vars.mlx = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx, x_res, y_res, "FRACTOL DE FOU EN VRAI");

	mlx_hook(vars.mlx_window, 2, 1L<<0, close_window(27, &vars), &vars);

	img.img = mlx_new_image(vars.mlx, x_res, y_res);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// rectangle, circle and triforce

	ratio_rectangle(img, x_res, y_res, 0x004B0082);

	bresenham_circle(img, x_res / 2, y_res / 2, 325, 0x00E6E6FA);
	bresenham_surligner(img, x_res / 2, y_res / 2, 325, add_shade(0.15, 0x00CD853F));

	triforce_color = 0x00DAA520;
	triforce_maker(img, x_res / 2, y_res / 2 - 200, add_shade(0.99, triforce_color));
	triforce_maker(img, x_res / 2 + (150 * 0.75), y_res / 2 - 50, add_shade(0.96, triforce_color));
	triforce_maker(img, x_res / 2 - (150 * 0.75), y_res / 2 - 50, add_shade(0.93, triforce_color));
	triforce_surligner(img, x_res / 2, y_res / 2 - 200, add_shade(0.5, 0x004B0082));

	mlx_put_image_to_window(vars.mlx, vars.mlx_window, img.img, 0, 0);
	mlx_loop(vars.mlx);
	free(vars.mlx_window);
	free(vars.mlx);
	return (0);
}
