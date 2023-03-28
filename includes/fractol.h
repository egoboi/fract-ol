/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:06:16 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/28 16:12:21 by fbrisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>

// Aspect ratio 16:9 (480 : 270, 960 : 540, 1920 : 1080, 2304 : 1296)
# define WINDOW_WIDTH 2304
# define WINDOW_HEIGHT 1296

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;


typedef struct s_fract
{
	int	max_iter;
	void	*mlx_ptr;
	void	*mlx_window;
	double	x_min;
	double	y_min;
	double	width;
	double	height;
	double	zoom;
	t_data	*img;
}		t_fract;

typedef struct s_complex
{
	double	r;
	double	i;
}		t_complex;

int	main(void);

int	get_opposite(int color);
int	add_shade(double distance, int color);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_params(t_fract *fdata);

void	ratio_rectangle(t_data img, int x, int y, int color);
void	bresenham_circle(t_data img, int x1, int y1, int r, int color);
void	bresenham_circle_draw(t_data img, int xctr, int yctr, int x, int y, int color);
void	bresenham_surligner(t_data img, int x1, int y1, int r, int color);
void	triforce_maker(t_data img,int y1, int x, int y, int color);
void	triforce_surligner(t_data img, int y1, int x, int y, int color);

void	mandelbrot_drawer(int x, int y, t_fract *data);

int	handle_no_event(void *data);
int	handle_keypress(int keycode, t_fract *data);
int	handle_keyrelease(int keycode, void *data);
int	handle_mouse_motion(int x, int y, void *data);
int	handle_mouse_action(t_fract *data);

#endif
