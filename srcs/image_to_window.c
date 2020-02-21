/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:22:01 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 18:31:54 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_to_win(t_mlx *mlx_arr, int y, int x)
{
	while (y < mlx_arr->map_size[0] - 1)
	{
		x = 0;
		while (x < mlx_arr->map_size[1] - 1)
		{
			mlx_arr->c = mlx_arr->r == 0 ? mlx_arr->map[y][x][1] :
				rainbow(mlx_arr, mlx_arr->map[y][x][0]);
			mlx_arr->x1 = mlx_arr->vector[y][x][0];
			mlx_arr->y1 = mlx_arr->vector[y][x][1];
			mlx_arr->x2 = mlx_arr->vector[y][x + 1][0];
			mlx_arr->y2 = mlx_arr->vector[y][x + 1][1];
			mlx_arr->c1 = mlx_arr->r == 0 ? mlx_arr->map[y][x + 1][1] :
				rainbow(mlx_arr, mlx_arr->map[y][x + 1][0]);
			line(mlx_arr);
			mlx_arr->c1 = mlx_arr->r == 0 ? mlx_arr->map[y + 1][x][1] :
				rainbow(mlx_arr, mlx_arr->map[y + 1][x][0]);
			mlx_arr->x1 = mlx_arr->vector[y][x][0];
			mlx_arr->y1 = mlx_arr->vector[y][x][1];
			mlx_arr->x2 = mlx_arr->vector[y + 1][x][0];
			mlx_arr->y2 = mlx_arr->vector[y + 1][x][1];
			line(mlx_arr);
			x++;
		}
		y++;
	}
}

void	image_clear(t_mlx *mlx_arr, int y, int x)
{
	mlx_arr->c = 0x000000;
	mlx_arr->c1 = 0x000000;
	while (y < mlx_arr->map_size[0] - 1)
	{
		x = 0;
		while (x < mlx_arr->map_size[1] - 1)
		{
			mlx_arr->x1 = mlx_arr->vector[y][x][0];
			mlx_arr->y1 = mlx_arr->vector[y][x][1];
			mlx_arr->x2 = mlx_arr->vector[y][x + 1][0];
			mlx_arr->y2 = mlx_arr->vector[y][x + 1][1];
			line(mlx_arr);
			mlx_arr->x1 = mlx_arr->vector[y][x][0];
			mlx_arr->y1 = mlx_arr->vector[y][x][1];
			mlx_arr->x2 = mlx_arr->vector[y + 1][x][0];
			mlx_arr->y2 = mlx_arr->vector[y + 1][x][1];
			line(mlx_arr);
			x++;
		}
		y++;
	}
}
