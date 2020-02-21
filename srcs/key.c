/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:31:48 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 18:52:52 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		reset(t_mlx *mlx_arr)
{
	mlx_arr->cam[2] = 0;
	mlx_arr->cam[3] = 0;
	mlx_arr->cam[4] = 0;
	mlx_arr->size[0] = 1;
	mlx_arr->size[1] = START_SIZE;
	mlx_arr->size[2] = START_SIZE;
}

static int		key_codes(int key, t_mlx *mlx_arr)
{
	if (key == 126 || key == 125)
		mlx_arr->cam[1] += 126 == key ? -25 : 25;
	else if (key == 123 || key == 124)
		mlx_arr->cam[0] += 123 == key ? -25 : 25;
	else if (key == 13 || key == 1)
		mlx_arr->cam[2] += key == 13 ? -0.1 : 0.1;
	else if (key == 0 || key == 2)
		mlx_arr->cam[3] += key == 0 ? -0.1 : 0.1;
	else if (key == 12 || key == 14)
		mlx_arr->cam[4] += key == 12 ? -0.1 : 0.1;
	else if (key == 16 || key == 32)
		mlx_arr->size[0] += key == 16 ? -0.1 : 0.1;
	else if (key == 89 || key == 85)
		mlx_arr->size[1] += key == 89 ? -0.1 : 0.1;
	else if (key == 92 || key == 83)
		mlx_arr->size[2] += key == 92 ? -0.1 : 0.1;
	else if (key == 34 || key == 35)
		mlx_arr->type = 34 == key ? 1 : 2;
	else if (key == 43 || key == 47)
		mlx_arr->spectrum += 43 == key ? -1 : 1;
	else if (key == 8)
		mlx_arr->r = mlx_arr->r == 1 ? 0 : 1;
	else
		return (0);
	return (1);
}

int				key_press(int key, t_mlx *mlx_arr)
{
	key == 53 ? exit(0) : 0;
	if (key == 78 || key == 69)
	{
		mlx_arr->size[1] += 78 == key ? -1 : 1;
		mlx_arr->size[2] += 78 == key ? -1 : 1;
	}
	else if (key == 49)
		reset(mlx_arr);
	else if (key == 4)
	{
		mlx_arr->menu = mlx_arr->menu == 1 ? 0 : 1;
		mlx_arr->menu == 0 ? fill(mlx_arr, 220, 180, 0x000000) : 0;
	}
	else if (key_codes(key, mlx_arr) == 1)
		;
	else
	{
		write(1, "Error key:(", 11);
		ft_putnbr(key);
		write(1, ") has no function.\nFor help press 'H'\n", 38);
	}
	re_draw(mlx_arr);
	mlx_arr->menu == 1 ? fill(mlx_arr, 220, 180, 0x000000) : 0;
	mlx_arr->menu == 1 ? info(mlx_arr) : 0;
	return (0);
}
