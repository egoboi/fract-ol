/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:15:37 by fbrisson          #+#    #+#             */
/*   Updated: 2023/04/04 15:51:04 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fract		fdata;

	//if (ac < 2)
	//	print_helper();

	init_params(&fdata);
	init_img(&fdata);
	render(&fdata);

	// SETTING UP HOOKS

	mlx_loop_hook(fdata.mlx_ptr, &handle_no_event, &fdata);
	mlx_hook(fdata.mlx_window, 2, 1L << 0, &handle_keypress, &fdata);
	mlx_hook(fdata.mlx_window, 6, 1L << 6, &handle_mouse, &fdata);
	mlx_hook(fdata.mlx_window, 4, 1L << 2, &handle_mouse, &fdata);
	mlx_hook(fdata.mlx_window, 17, 0, &handle_mouse_exit, &fdata);

	printf("INITIALIZING <HOOKS> : [\e[1;32mOK\e[0m] \n");

	printf("INITIALIZING MANDELBROT SET : [\e[1;32mOK\e[0m] \n");

	// STARTING THE LOOP

	mlx_loop(fdata.mlx_ptr);

	// HANDLING END OF PROGRAM

	//mlx_destroy_image(fdata->mlx_ptr, img.img);
	//mlx_destroy_display(fdata->mlx_ptr);
	return (0);
}
