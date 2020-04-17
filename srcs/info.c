/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:22:38 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 18:00:16 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	info(t_mlx *mlx_arr)
{
	int color;

	color = 0xFFFFFF;
	mlx_string_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, 25, 15, color,
			"MoveCam: Arrow keys");
	mlx_string_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, 25, 35, color,
			"Zoom: z, x");
	mlx_string_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, 25, 55, color,
			"RgbToggle: c");
	mlx_string_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, 25, 75, color,
			"ScaleRGB: <, >");
	mlx_string_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, 25, 95, color,
			"Map: wasd or mouse");
	mlx_string_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, 25, 115, color,
			"Reset: Space");
	mlx_string_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, 25, 135, color,
			"Projection: i, p");
	mlx_string_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, 25, 155, color,
			"Sretch: NumPad");
}
