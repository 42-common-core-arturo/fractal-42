/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:58:27 by artclave          #+#    #+#             */
/*   Updated: 2024/01/24 14:10:31 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (!parsing(ac, av, &mlx))
		return (error_message());
	initialize_mlx(&mlx);
	draw(&mlx);
	events(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
