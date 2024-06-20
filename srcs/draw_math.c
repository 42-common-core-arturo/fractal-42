/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 04:06:00 by artclave          #+#    #+#             */
/*   Updated: 2024/03/01 08:02:03 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	map(double pixel, double total_pixels,
		double fractal_min, double fractal_max)
{
	double	result;

	result = fractal_min + ((fractal_max - fractal_min)
			/ (total_pixels - 1) * pixel);
	return (result);
}

int	lerp_colors(int color_start, int color_end, double step)
{
	t_color	color;

	if (step > 0.98)
	{
		color_start = 0x00000FF;
		color_end = 0x00000AA;
	}
	color.r1 = (color_start >> 16) & 0xFF;
	color.g1 = (color_start >> 8) & 0xFF;
	color.b1 = (color_start) & 0xFF;
	color.r2 = (color_end >> 16) & 0xFF;
	color.g2 = (color_end >> 8) & 0xFF;
	color.b2 = (color_end) & 0xFF;
	color.r_new = (int)((color.r1 * (1 - step)) + (color.r2 * step));
	color.g_new = (int)((color.g1 * (1 - step)) + (color.g2 * step));
	color.b_new = (int)((color.b1 * (1 - step)) + (color.b2 * step));
	return (color.r_new << 16 | color.g_new << 8 | color.b_new);
}

double	complex_hypotenuse(t_coordinates *z, t_coordinates c)
{
	double	temp;
	double	hypo;

	temp = (z->x * z->x) - (z->y * z->y) + c.x;
	z->y = ((2 * z->x * z->y) + c.y);
	z->x = temp;
	hypo = (z->x * z->x) + (z->y * z->y);
	return (hypo);
}

int	is_mandelbrot(t_coordinates c, t_color color)
{
	t_coordinates	z;
	double			i;

	i = -1.0;
	z.iterations = 1000;
	z.x = 0;
	z.y = 0;
	while (++i < z.iterations)
	{
		if (complex_hypotenuse(&z, c) > 4)
			break ;
	}
	if (i == z.iterations)
		return (color.palette[0]);
	return (lerp_colors(color.palette[4], color.palette[2], i / z.iterations));
}

int	is_julia(t_coordinates z1, t_coordinates c)
{
	double			i;
	t_coordinates	z2;

	i = -1.0;
	z2.iterations = 30;
	z2.x = z1.x;
	z2.y = z1.y;
	while (++i < z2.iterations)
	{
		if (complex_hypotenuse(&z2, c) > 2)
			break ;
	}
	if (i == z2.iterations)
		return (0x0E7FFCE);
	return (lerp_colors(0x000A86B, 0x0043927, i / z2.iterations));
}
