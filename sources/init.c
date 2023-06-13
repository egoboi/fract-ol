/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:47:43 by fbrisson          #+#    #+#             */
/*   Updated: 2023/06/13 15:29:41 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_params(t_fract *fdata)
{
	//fdata = malloc(sizeof(*fdata));
	//if (!fdata)
	//	exit_prog("fdata : MALLOC FAILED");
	fdata->mlx_ptr = mlx_init();
	if (!fdata->mlx_ptr)
		exit_prog("[\e[1;31mERROR\e[0m] : MLX_PTR");
	fdata->mlx_window = mlx_new_window(fdata->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FRACTOL DE FOU EN VRAI");
	if (!fdata->mlx_window)
		exit_prog("[\e[1;31mERROR\e[0m] : MLX_WINDOW");

	fdata->zoom =  1; //WINDOW_WIDTH / 4;
	// fdata->x_min = -0.7 * (WINDOW_WIDTH / fdata->zoom);
	// fdata->y_min = -0.5 * (WINDOW_HEIGHT / fdata->zoom);
	fdata->center_i = 0;// -0.286768;
	fdata->center_r = -0.5;// -0.0000001;
	fdata->width = 3;
	fdata->height = ( (float) WINDOW_HEIGHT /  (float) WINDOW_WIDTH) * fdata->width;
	fdata->max_iter = 100;

	fdata->min_r = -2.0;
	fdata->max_r = 1.0;
	fdata->min_i = -1.5;
	fdata->max_i = fdata->max_i + (fdata->max_r - fdata->min_r) * WINDOW_HEIGHT / WINDOW_WIDTH;

	printf("INITIALIZING <fdata_PARAMETERS> : [\e[1;32mOK\e[0m] \n");
}

void	init_img(t_fract *fdata)
{
	t_data	img;

	img.img = mlx_new_image(fdata->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.width = WINDOW_WIDTH;
	img.height = WINDOW_HEIGHT;
	fdata->img = img;
}
