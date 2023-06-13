/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:17:43 by fbrisson          #+#    #+#             */
/*   Updated: 2023/05/25 10:26:13 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(void *fdata)
{
	return (0);
}

int	handle_keypress(int keycode, t_fract *fdata)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(fdata->mlx_ptr, fdata->mlx_window);
		printf("[\e[1;31mESCAPE\e[0m] (keycode : %d)\n", keycode);
	}
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_NUMPAD)
	{
		printf("[\e[1;31m+\e[0m] (keycode : %d)\n", keycode);
		viewport_zoom(fdata, 0.5);
	}
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_NUMPAD)
	{
		printf("[\e[1;31m-\e[0m] (keycode : %d)\n", keycode);
		viewport_zoom(fdata, 2);
	}
	//printf("[\e[1;31m?\e[0m] (keycode : %d)\n", keycode);
	render(fdata);
	return (0);
}

int	handle_mouse(int keycode, int x, int y, t_fract *fdata)
{
	
	if ((x > WINDOW_WIDTH - WINDOW_WIDTH && x < WINDOW_WIDTH)
		|| (y > WINDOW_HEIGHT - WINDOW_HEIGHT && y < WINDOW_HEIGHT))
	{
		printf("Mouse POS x:[\e[1;34m%d\e[0m], y:[\e[1;34m%d\e[0m] \n", x, y);
	}
	
	return (0);
}

int	handle_mouse_exit(t_fract *fdata)
{
	mlx_destroy_window(fdata->mlx_ptr, fdata->mlx_window);
	printf("[\e[1;31mEXIT\e[0m] (clicked) \n");
	return (0);
}
