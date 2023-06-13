/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:51:44 by fbrisson          #+#    #+#             */
/*   Updated: 2023/06/13 16:47:13 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	viewport_zoom(t_fract *fdata, double zoom_factor)
{
	double	c_r;
	double	c_i;

	c_r = fdata->min_r - fdata->max_r;
	c_i = fdata->min_i - fdata->max_i;
	fdata->max_r = fdata->max_r + (c_r - zoom_factor * c_r) / 2;
	fdata->min_r = fdata->max_r + zoom_factor * c_r;
	fdata->max_i = fdata->min_i + (c_i - zoom_factor * c_i) / 2;
	fdata->min_i = fdata->min_i + zoom_factor * c_i;
}
