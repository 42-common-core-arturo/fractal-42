/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:54:50 by artclave          #+#    #+#             */
/*   Updated: 2024/01/24 14:40:11 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_fractal_range(t_mlx *mlx)
{
	mlx->range.x_max = (1.5 * mlx->zoom) + (mlx->shift_x * mlx->zoom);
	mlx->range.y_max = (2 * mlx->zoom) + (mlx->shift_y * mlx->zoom);
	mlx->range.x_min = (-2.5 * mlx->zoom) + (mlx->shift_x * mlx->zoom);
	mlx->range.y_min = (-2 * mlx->zoom) + (mlx->shift_y * mlx->zoom);
	if (mlx->set == 'j')
	{
		mlx->range.x_max += (0.5 * mlx->zoom);
		mlx->range.x_min += (0.5 * mlx->zoom);
	}
}

void	plot_points_mandelbrot(t_mlx *mlx)
{
	t_coordinates	pixel;
	t_coordinates	c;

	pixel.y = -1;
	while (++pixel.y < mlx->height)
	{
		c.y = map(pixel.y, mlx->height, mlx->range.y_max, mlx->range.y_min);
		pixel.x = -1;
		while (++pixel.x < mlx->width)
		{
			c.x = map(pixel.x, mlx->width, mlx->range.x_min, mlx->range.x_max);
			pixel.color = is_mandelbrot(c, mlx->color);
			ft_mlx_pixel_put(&mlx->image, pixel.x, pixel.y, pixel.color);
		}
	}
}

void	plot_points_julia(t_mlx *mlx, t_coordinates c)
{
	t_coordinates	pixel;
	t_coordinates	z;

	pixel.y = -1;
	while (++pixel.y < mlx->height)
	{
		z.y = map(pixel.y, mlx->height, mlx->range.y_max, mlx->range.y_min);
		pixel.x = -1;
		while (++pixel.x < mlx->width)
		{
			z.x = map(pixel.x, mlx->width, mlx->range.x_min, mlx->range.x_max);
			pixel.color = is_julia(z, c);
			ft_mlx_pixel_put(&mlx->image, pixel.x, pixel.y, pixel.color);
		}
	}
}

void	draw(t_mlx *mlx)
{
	set_fractal_range(mlx);
	if (mlx->set == 'j')
		plot_points_julia(mlx, mlx->c);
	if (mlx->set == 'm')
		plot_points_mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image.img, 0, 0);
}
