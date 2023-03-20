/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:06:16 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/20 18:38:20 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_vars {
	void	*mlx;
	void	*mlx_window;
}		t_vars;

int	main(void);

int	get_opposite(int color);
int	add_shade(double distance, int color);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ratio_rectangle(t_data img, int x, int y, int color);
void	bresenham_circle(t_data img, int x1, int y1, int r, int color);
void	bresenham_circle_draw(t_data img, int xctr, int yctr, int x, int y, int color);
void	bresenham_surligner(t_data img, int x1, int y1, int r, int color);
void	triforce_maker(t_data img, int x, int y, int color);
void	triforce_surligner(t_data img, int x, int y, int color);

#endif
