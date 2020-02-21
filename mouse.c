/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:14:52 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 19:24:21 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_move(int x, int y, t_mlx *mlx_arr)
{
	int tmp_x;
	int tmp_y;

	tmp_x = mlx_arr->mouse[0];
	tmp_y = mlx_arr->mouse[1];
	mlx_arr->mouse[0] = x;
	mlx_arr->mouse[1] = y;
	if (mlx_arr->press == 1)
	{
		mlx_arr->cam[2] += (x - tmp_x) * 0.005;
        mlx_arr->cam[3] += (y - tmp_y) * 0.005;
		re_draw(mlx_arr);
	}
	return (0);
}

int	mouse_release(int key, int x, int y, t_mlx *mlx_arr)
{
	mlx_arr->press = 0;
	return (0);
}

int	mouse_press(int key, int x, int y, t_mlx *mlx_arr)
{
	if (key == 4 || key == 5)
	{
		mlx_arr->size[1] += 4 == key ? -1 : 1;
		mlx_arr->size[2] += 4 == key ? -1 : 1;
		re_draw(mlx_arr);
	}
	else if (key == 1)
		mlx_arr->press = 1;
	return (0);
}
