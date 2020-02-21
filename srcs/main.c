/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:14:16 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 19:06:27 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		preset(t_mlx *mlx_arr)
{
	mlx_arr->type = 1;
	mlx_arr->menu = 0;
	mlx_arr->cam[0] = WIN_HIGHT / 2;
	mlx_arr->cam[1] = WIN_WIDTH / 4;
	mlx_arr->cam[2] = 0;
	mlx_arr->cam[3] = 0;
	mlx_arr->cam[4] = 0;
	mlx_arr->size[0] = 1;
	mlx_arr->size[1] = START_SIZE;
	mlx_arr->size[2] = START_SIZE;
	mlx_arr->press = 0;
	mlx_arr->win_size[0] = WIN_WIDTH;
	mlx_arr->win_size[1] = WIN_HIGHT;
	mlx_arr->spectrum = RGB;
	mlx_arr->r = 0;
}

void			re_draw(t_mlx *mlx_arr)
{
	image_clear(mlx_arr, 0, 0);
	mlx_arr->type == 1 ?
		calculate_iso(mlx_arr, 0, 0) : calculate_paralel(mlx_arr, 0, 0);
}

static void		controls(t_mlx *mlx_arr)
{
	mlx_hook(mlx_arr->win_ptr, 2, 0, key_press, mlx_arr);
	mlx_hook(mlx_arr->win_ptr, 4, 0, mouse_press, mlx_arr);
	mlx_hook(mlx_arr->win_ptr, 5, 0, mouse_release, mlx_arr);
	mlx_hook(mlx_arr->win_ptr, 6, 0, mouse_move, mlx_arr);
}

int				main(int ac, char **av)
{
	t_mlx	*mlx_arr;

	if (av[1] == NULL || ac == 1)
	{
		ft_putstr("Error: No file given\n");
		return (0);
	}
	if (!(mlx_arr = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	mlx_arr->file = av[1];
	if (read_file(mlx_arr) == -1)
	{
		ft_putstr("Error: File is empty or not a valide file.\n");
		return (0);
	}
	preset(mlx_arr);
	mlx_arr->mlx_ptr = mlx_init();
	mlx_arr->win_ptr = mlx_new_window(mlx_arr->mlx_ptr,
			mlx_arr->win_size[0], mlx_arr->win_size[1], "FDF");
	new_array(mlx_arr);
	mlx_arr->type == 1 ?
		calculate_iso(mlx_arr, 0, 0) : calculate_paralel(mlx_arr, 0, 0);
	controls(mlx_arr);
	mlx_loop(mlx_arr->mlx_ptr);
}
