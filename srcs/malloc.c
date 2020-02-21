/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:05:29 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 10:20:54 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_array(t_mlx *mlx_arr)
{
	int x;
	int y;

	y = 0;
	mlx_arr->vector =
		(int ***)malloc(sizeof(int **) * mlx_arr->map_size[0]);
	while (mlx_arr->map_size[0] > y)
	{
		x = 0;
		mlx_arr->vector[y] =
			(int **)malloc(sizeof(int *) * mlx_arr->map_size[1]);
		while (mlx_arr->map_size[1] > x)
		{
			mlx_arr->vector[y][x] = (int *)malloc(sizeof(int) * 2);
			x++;
		}
		y++;
	}
}
