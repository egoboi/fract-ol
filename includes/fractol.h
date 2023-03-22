/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:06:16 by fbrisson          #+#    #+#             */
/*   Updated: 2023/03/22 15:53:43 by fbrisson         ###   ########.fr       */
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

// Aspect ratio 16:9 (480 : 270, 960 : 540, 1920 : 1080)
# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 540

typedef struct s_data 
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_complex
{
	double	r;
	double	i;
}		t_complex;

int	main(void);

int	get_opposite(int color);
int	add_shade(double distance, int color);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ratio_rectangle(t_data img, int x, int y, int color);
void	bresenham_circle(t_data img, int x1, int y1, int r, int color);
void	bresenham_circle_draw(t_data img, int xctr, int yctr, int x, int y, int color);
void	bresenham_surligner(t_data img, int x1, int y1, int r, int color);
void	triforce_maker(t_data img,int y1, int x, int y, int color);
void	triforce_surligner(t_data img, int y1, int x, int y, int color);

void	mandelbrot_algo(t_data img, int x1, int y1);

int	handle_no_event(void *data);
int	handle_keypress(int keycode, t_data *data);
int	handle_keyrelease(int keycode, void *data);
int	handle_mouse_motion(int x, int y, void *data);
int	handle_mouse_action(t_data *data);

#endif
