/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:17:43 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/28 13:24:00 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keypress(int keycode, t_fract *data)
{
	if (keycode == 65307)
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	if (keycode == 65436)
		printf("that's the numpad 1, for sure \n");
	printf("key pressed : %d\n", keycode);
	return (0);
}

int	handle_mouse_motion(int x, int y, void *data)
{
	if ((x > WINDOW_WIDTH - WINDOW_WIDTH && x < WINDOW_WIDTH)
		|| (y > WINDOW_HEIGHT - WINDOW_HEIGHT && y < WINDOW_HEIGHT))
	{
		printf("hello there x:[%d], y:[%d]\n", x, y);
	}
	return (0);
}

int	handle_mouse_action(t_fract *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	printf("clicked exit");
	return (0);
}
