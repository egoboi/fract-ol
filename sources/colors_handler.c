/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:27:04 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/20 15:23:17 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	add_shade(double distance, int color)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	new_trgb;

	t = get_t(color);
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	r *= distance;
	g *= distance;
	b *= distance;
	new_trgb = create_trgb(t, r, g, b);
	return (new_trgb);
}

int	get_opposite(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	new_trgb;

	t = get_t(color);
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	r = 255 - r;
	g = 255 - g;
	b = 255 - b;
	new_trgb = create_trgb(t, r, g, b);
	return (new_trgb);
}
