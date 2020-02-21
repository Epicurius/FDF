/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:34:05 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 19:09:05 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill(t_mlx *mlx_arr, int x1, int y2, int color)
{
	int x;
	int y;

	y = 0;
	while (y <= y2)
	{
		x = 0;
		while (x++ <= x1)
			mlx_pixel_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, x, y, color);
		y++;
	}
}

double	line_calc(t_mlx *mlx_arr)
{
	double pytha;

	pytha = sqrt(pow((mlx_arr->x2 - mlx_arr->x1), 2)
			+ pow((mlx_arr->y2 - mlx_arr->y1), 2));
	mlx_arr->cath[0] = (mlx_arr->y2 - mlx_arr->y1) < 0 ?
		(mlx_arr->y2 - mlx_arr->y1) * -1 : (mlx_arr->y2 - mlx_arr->y1);
	mlx_arr->cath[1] = (mlx_arr->x2 - mlx_arr->x1) < 0 ?
		(mlx_arr->x2 - mlx_arr->x1) * -1 : (mlx_arr->x2 - mlx_arr->x1);
	mlx_arr->xy[0] = mlx_arr->x1 < mlx_arr->x2 ? 1 : -1;
	mlx_arr->xy[1] = mlx_arr->y1 < mlx_arr->y2 ? 1 : -1;
	ft_rgb(mlx_arr);
	return (pytha);
}

void	line(t_mlx *mlx_arr)
{
	int		i;
	double	pytha;

	i = 0;
	pytha = line_calc(mlx_arr);
	mlx_arr->overflow[1] = mlx_arr->cath[1] - mlx_arr->cath[0];
	while (mlx_arr->x1 != mlx_arr->x2 || mlx_arr->y1 != mlx_arr->y2)
	{
		if ((mlx_arr->x1 > 0 && mlx_arr->x1 < WIN_WIDTH)
				&& (mlx_arr->y1 > 0 && mlx_arr->y1 < WIN_HIGHT))
			mlx_pixel_put(mlx_arr->mlx_ptr, mlx_arr->win_ptr, mlx_arr->x1,
					mlx_arr->y1, ft_gradient(mlx_arr->rgb,
						i++ / (pytha + (pytha / 2))));
		mlx_arr->overflow[0] = mlx_arr->overflow[1] * 2;
		if (mlx_arr->overflow[0] > -(mlx_arr->cath[0]))
		{
			mlx_arr->overflow[1] -= mlx_arr->cath[0];
			mlx_arr->x1 += mlx_arr->xy[0];
		}
		else if (mlx_arr->overflow[0] < mlx_arr->cath[0])
		{
			mlx_arr->overflow[1] += mlx_arr->cath[1];
			mlx_arr->y1 += mlx_arr->xy[1];
		}
	}
}
