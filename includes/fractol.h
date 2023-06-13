/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <fbrisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:06:16 by fbrisson          #+#    #+#             */
/*   Updated: 2023/06/13 16:10:22 by fbrisson         ###   ########.fr       */
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
# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 960

// Keycodes
# define KEY_ESCAPE 65307
# define KEY_PLUS 61
# define KEY_PLUS_NUMPAD 65451
# define KEY_MINUS 45
# define KEY_MINUS_NUMPAD 65453

typedef struct s_data 
{
	void		*img;
	char		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_camera
{
	t_vector	pos;
	t_vector	size;
}				t_camera;

typedef struct s_fract
{
	int		max_iter;
	void		*mlx_ptr;
	void		*mlx_window;
	double		x_min;
	double		y_min;
	double		width;
	double		height;
	double		zoom;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		center_i;
	double		center_r;
	t_data		img;
	t_camera	camera;
	t_complex	vector;
}				t_fract;

int	main(int ac, char **av);

int	get_opposite(int color);
int	add_shade(double distance, int color);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_params(t_fract *fdata);
void	viewport_zoom(t_fract *fdata, double zoom_factor);
void	init_img(t_fract *fdata);
void	print_helper();
void	exit_prog(char *error_msg);

int		mandelbrot_algo(double x, double y, t_fract *fdata);

void	render(t_fract *data);

int	handle_no_event(void *data);
int	handle_keypress(int keycode, t_fract *data);
int	handle_keyrelease(int keycode, void *data);
int	handle_mouse(int keycode, int x, int y, t_fract *data);
int	handle_mouse_exit(t_fract *data);

#endif
