/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:07:05 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 17:01:10 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_paralel(t_mlx *mlx_arr, int dx, int dy)
{
	int yxz[3];

	yxz[0] = 0;
	while (yxz[0] < mlx_arr->map_size[0])
	{
		yxz[1] = 0;
		while (yxz[1] < mlx_arr->map_size[1])
		{
			dx = yxz[1];
			dy = yxz[0];
			yxz[2] = mlx_arr->map[yxz[0]][yxz[1]][0] * mlx_arr->size[0];
			dx *= mlx_arr->size[1];
			dy *= mlx_arr->size[2];
			rotate_x(&dy, &yxz[2], mlx_arr->cam[2]);
			rotate_y(&dx, &yxz[2], mlx_arr->cam[3]);
			rotate_z(&dx, &dy, mlx_arr->cam[4]);
			mlx_arr->vector[yxz[0]][yxz[1]][0] = dx + mlx_arr->cam[0];
			mlx_arr->vector[yxz[0]][yxz[1]][1] = dy + mlx_arr->cam[1];
			yxz[1]++;
		}
		yxz[0]++;
	}
	image_to_win(mlx_arr, 0, 0);
}

void	calculate_iso(t_mlx *mlx_arr, int dx, int dy)
{
	int yxz[3];

	yxz[0] = 0;
	while (yxz[0] < mlx_arr->map_size[0])
	{
		yxz[1] = 0;
		while (yxz[1] < mlx_arr->map_size[1])
		{
			dx = yxz[1];
			dy = yxz[0];
			yxz[2] = mlx_arr->map[yxz[0]][yxz[1]][0] * mlx_arr->size[0];
			dx *= mlx_arr->size[1];
			dy *= mlx_arr->size[2];
			rotate_x(&dy, &yxz[2], mlx_arr->cam[2]);
			rotate_y(&dx, &yxz[2], mlx_arr->cam[3]);
			rotate_z(&dx, &dy, mlx_arr->cam[4]);
			mlx_arr->vector[yxz[0]][yxz[1]][0] = (dx - dy) + mlx_arr->cam[0];
			mlx_arr->vector[yxz[0]][yxz[1]][1] =
				-yxz[2] + (dx + dy) + mlx_arr->cam[1];
			yxz[1]++;
		}
		yxz[0]++;
	}
	image_to_win(mlx_arr, 0, 0);
}
