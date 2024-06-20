/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:15:33 by artclave          #+#    #+#             */
/*   Updated: 2024/01/30 16:40:28 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <time.h>

void	reset_values(t_mlx *mlx)
{
	mlx->zoom = 1;
	mlx->shift_x = 0;
	mlx->shift_y = 0;
	draw(mlx);
}

int	kill(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == 24)
		zoom(mlx, 1, 1);
	if (key == 27)
		zoom(mlx, -1, 1);
	if (key == 126 || key == 13)
		move(mlx, 12, 1);
	if (key == 124 || key == 2)
		move(mlx, 3, 1);
	if (key == 125 || key == 1)
		move(mlx, 6, 1);
	if (key == 123 || key == 0)
		move(mlx, 9, 1);
	if (key == 12 || key == 7 || key == 53)
		escape(mlx);
	if (key == 15)
		reset_values(mlx);
	return (0);
}

int	mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == 1)
		re_center(mlx, x, y, 1);
	if (button == 2)
		re_center(mlx, x, y, 0);
	if (button == 4)
		zoom(mlx, -1, .1);
	if (button == 5)
		zoom(mlx, 1, .1);
	return (0);
}

void	events(t_mlx *mlx)
{
	mlx_hook(mlx->window, KeyPress, KeyPressMask, key_press, mlx);
	mlx_hook(mlx->window, ButtonPress, ButtonPressMask, mouse, mlx);
	mlx_hook(mlx->window, DestroyNotify, StructureNotifyMask, kill, mlx);
}
