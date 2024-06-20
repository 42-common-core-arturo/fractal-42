/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:57:23 by artclave          #+#    #+#             */
/*   Updated: 2024/01/30 16:41:54 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <complex.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_range
{
	double	x_max;
	double	x_min;
	double	y_min;
	double	y_max;
}			t_range;

typedef struct s_color
{
	int		palette[6];
	int		palette_size;
	double	palette_ratio;
	int		total_lerps;
	double	lerp_step;
	int		r1;
	int		r2;
	int		r_new;
	int		g1;
	int		g2;
	int		g_new;
	int		b1;
	int		b2;
	int		b_new;
}		t_color;

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		iterations;
}		t_coordinates;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	t_data			image;
	double			height;
	double			width;
	double			c_values[4][2];
	t_coordinates	c;
	char			set;
	double			zoom;
	t_range			range;
	double			shift_x;
	double			shift_y;
	t_color			color;
}		t_mlx;

int		main(int ac, char **av);
int		error_message(void);
int		parsing(int ac, char **av, t_mlx *mlx);
void	initialize_mlx(t_mlx *mlx);
void	color_list(t_mlx *mlx);
void	draw(t_mlx *mlx);
void	plot_points_julia(t_mlx *mlx, t_coordinates c);
void	plot_points_mandelbrot(t_mlx *mlx);
void	set_fractal_range(t_mlx *mlx);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		is_julia(t_coordinates z1, t_coordinates c);
int		is_mandelbrot(t_coordinates c, t_color color);
double	complex_hypotenuse(t_coordinates *z, t_coordinates c);
int		lerp_colors(int color_start, int color_end, double step);
double	map(double pixel, double total_pixels, double fractal_min,
			double fractal_max);
void	events(t_mlx *mlx);
int		key_press(int key, t_mlx *mlx);
void	zoom(t_mlx *mlx, double signed_direction, double size);
void	reset_values(t_mlx *mlx);
int		kill(t_mlx *mlx);
int		mouse(int button, int x, int y, t_mlx *mlx);
void	re_center(t_mlx *mlx, int x, int y, int zoom);
void	move(t_mlx *mlx, int o_clock_direction, double size);
void	escape(t_mlx *mlx);

#endif
