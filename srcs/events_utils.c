/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:22:28 by artclave          #+#    #+#             */
/*   Updated: 2024/01/30 16:40:51 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


void	escape(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

void	move(t_mlx *mlx, int o_clock_direction, double size)
{
	double	factor;

	factor = 1 * size;
	if (o_clock_direction == 12)
		mlx->shift_y += factor;
	if (o_clock_direction == 3)
		mlx->shift_x += factor;
	if (o_clock_direction == 6)
		mlx->shift_y -= factor;
	if (o_clock_direction == 9)
		mlx->shift_x -= factor;
	draw(mlx);
}

void	re_center(t_mlx *mlx, int x, int y, int zoom)
{
	double	size;

	if (zoom)
	{
		mlx->zoom *= .4;
	}
	if (x > 0 && x < mlx->width)
	{
		size = 4 * (((mlx->width / 2) - x) / mlx->width);
		if (size < 0)
			move(mlx, 3, size * -1);
		else
			move(mlx, 9, size);
	}
	if (y > 0 && y < mlx->height)
	{
		size = 4 * (((mlx->height / 2) - y) / mlx->height);
		if (size < 0)
			move(mlx, 6, size * -1);
		else
			move(mlx, 12, size);
		return ;
	}
}

void	zoom(t_mlx *mlx, double signed_direction, double size)
{
	double	factor;

	factor = .5 * size;
	mlx->zoom *= (1 - (factor * signed_direction));
	draw(mlx);
}
