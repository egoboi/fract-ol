/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:47:43 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/28 16:13:29 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_params(t_fract *fdata)
{	
	fdata->zoom = WINDOW_WIDTH / 3.25;
	fdata->x_min = -0.7 * (WINDOW_WIDTH / fdata->zoom);
	fdata->y_min = -0.5 * (WINDOW_HEIGHT / fdata->zoom);
	fdata->width = WINDOW_WIDTH / fdata->zoom;
	fdata->height = WINDOW_HEIGHT / fdata->zoom;
	fdata->max_iter = 100;
}
