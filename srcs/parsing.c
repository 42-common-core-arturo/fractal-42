/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:00:28 by artclave          #+#    #+#             */
/*   Updated: 2024/01/30 15:33:51 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	error_message(void)
{
	write(2, "\nParsing Error!\n\nFor mandelbrot set: parse ", 43);
	write(2, "\'M\'\nFor julia set: parse \'J\'", 28);
	write(2, "and set number 1-4\n\n", 20);
	return (0);
}

int	parsing(int ac, char **av, t_mlx *mlx)
{
	if (ac > 3 || ac < 2)
		return (0);
	if ((av[1][0] == 'M' && av[1][1] == '\0') && ac == 2)
	{
		mlx->set = 'm';
		return (1);
	}
	mlx->c_values[0][0] = -0.8;
	mlx->c_values[0][1] = 0.156;
	mlx->c_values[1][0] = 0.355;
	mlx->c_values[1][1] = 0.355;
	mlx->c_values[2][0] = -0.54;
	mlx->c_values[2][1] = 0.54;
	mlx->c_values[3][0] = -0.7;
	mlx->c_values[3][1] = 0.27015;
	if ((av[1][0] == 'J' && av[1][1] == '\0') && ac == 3 && av[2][0] > '0'
		&& av[2][0] < '5' && av[2][1] == '\0')
	{
		mlx->c.x = mlx->c_values[(av[2][0] - '0') - 1][0];
		mlx->c.y = mlx->c_values[(av[2][0] - '0') - 1][1];
		mlx->set = 'j';
		return (1);
	}
	return (0);
}
