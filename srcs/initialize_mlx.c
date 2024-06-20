/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:40:55 by artclave          #+#    #+#             */
/*   Updated: 2024/01/24 16:45:53 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	color_list(t_mlx *mlx)
{
	mlx->color.palette[0] = 0x0000000;
	mlx->color.palette[1] = 0x02ECC40;
	mlx->color.palette[2] = 0x0FF007F;
	mlx->color.palette[3] = 0x09400D3;
	mlx->color.palette[4] = 0x000FFFF;
	mlx->color.palette[5] = 0x0BF55EC;
	mlx->color.palette_size = 6;
}

void	initialize_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->height = 800;
	mlx->width = 800;
	mlx->window = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "Fractal");
	mlx->image.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->image.address = mlx_get_data_addr(mlx->image.img,
			&mlx->image.bits_per_pixel,
			&mlx->image.line_length, &mlx->image.endian);
	color_list(mlx);
	mlx->zoom = 1;
	mlx->shift_x = 0;
	mlx->shift_y = 0;
}
