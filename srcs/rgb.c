/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:05:53 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 18:51:41 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_rgb(t_mlx *mlx_arr)
{
	mlx_arr->rgb[0] = (mlx_arr->c >> 16) & 0xFF;
	mlx_arr->rgb[1] = (mlx_arr->c >> 8) & 0xFF;
	mlx_arr->rgb[2] = (mlx_arr->c) & 0xFF;
	mlx_arr->rgb[3] = (mlx_arr->c1 >> 16) & 0xFF;
	mlx_arr->rgb[4] = (mlx_arr->c1 >> 8) & 0xFF;
	mlx_arr->rgb[5] = (mlx_arr->c1) & 0xFF;
}

int			ft_gradient(int *rgb, double i)
{
	int		r;
	int		g;
	int		b;
	int		color;

	r = (rgb[3] - rgb[0]) * i + rgb[0];
	g = (rgb[4] - rgb[1]) * i + rgb[1];
	b = (rgb[5] - rgb[2]) * i + rgb[2];
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

void		rgb_rainbow(t_mlx *mlx_arr, int *rgb, int a, int x)
{
	int c;

	c = 1;
	while (x++ < a)
	{
		while (x++ < a && rgb[1] < 255)
			rgb[1] += c;
		while (x++ < a && rgb[0] > 0)
			rgb[0] -= c;
		while (x++ < a && rgb[2] < 255)
			rgb[2] += c;
		while (x++ < a && rgb[1] > 0)
			rgb[1] -= c;
		while (x++ < a && rgb[0] < 255)
			rgb[0] += c;
		while (x++ < a && rgb[2] > 0)
			rgb[2] -= c;
	}
}

int			rainbow(t_mlx *mlx_arr, int a)
{
	int color;
	int x;
	int	rgb[3];

	x = 0;
	a *= a < 0 ? -1 : 1;
	a *= (mlx_arr->size[0] * mlx_arr->spectrum);
	if (a == 0)
		return (0xFFFFFF);
	rgb[0] = 255.0;
	rgb[1] = 0.0;
	rgb[2] = 0.0;
	rgb_rainbow(mlx_arr, rgb, a, x);
	color = ((rgb[0] & 0xFF) << 16 | (rgb[1] & 0xFF) << 8 | (rgb[2] & 0xFF));
	return (color);
}
