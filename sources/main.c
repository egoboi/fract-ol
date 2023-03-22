/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:15:37 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/22 15:53:47 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_data		img;
	t_data		data;
	int	triforce_color;

	// INITIALIZING THE MLX WINDOW

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (0);

	data.mlx_window = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FRACTOL DE FOU EN VRAI");
	if (data.mlx_window == NULL)
		return (free(data.mlx_window), 0);

	img.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// SETTING UP EVENTS

	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.mlx_window, 2, 1L << 0, &handle_keypress, &data);
	//mlx_hook(data.mlx_window, 6, 1L << 6, &handle_mouse_motion, &data);
	mlx_hook(data.mlx_window, 17, 0, &handle_mouse_action, &data);

	// HAVING FUN WITH SHAPES AND COLORS

	//ratio_rectangle(img, WINDOW_WIDTH, WINDOW_HEIGHT, 0x004B0082);

	//bresenham_circle(img, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_HEIGHT * 0.35, 0x00E6E6FA);
	//bresenham_surligner(img, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_HEIGHT * 0.35, add_shade(0.15, 0x00CD853F));

	//triforce_color = 0x00DAA520;
	//triforce_maker(img, WINDOW_HEIGHT, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.25, add_shade(0.99, triforce_color));
	//triforce_maker(img, WINDOW_HEIGHT, WINDOW_WIDTH / 2 * 1.17, WINDOW_HEIGHT * 0.45, add_shade(0.96, triforce_color));
	//triforce_maker(img, WINDOW_HEIGHT, WINDOW_WIDTH / 2 * 0.83, WINDOW_HEIGHT * 0.45, add_shade(0.93, triforce_color));
	//triforce_surligner(img, WINDOW_HEIGHT, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 * 0.50, add_shade(0.5, 0x004B0082));

	// MANDELBROT 1

	mandelbrot_algo(img, 0, 0);

	// SEND IMAGE TO MLX WINDOW

	mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, img.img, 0, 0);

	// STARTING THE LOOP

	mlx_loop(data.mlx_ptr);

	// HANDLING END OF PROGRAM

	mlx_destroy_image(data.mlx_ptr, img.img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
