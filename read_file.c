/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:11:29 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 18:26:53 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/get_next_line.h"
#include <fcntl.h>

void		read_values(t_mlx *mlx_arr, char **temp, int x, int y)
{
	int i;

	mlx_arr->map[y][x] = (int *)malloc(sizeof(int) * 2);
	mlx_arr->map[y][x][0] = ft_atoi(temp[x]);
	if (0 != (i = ft_strchrlen(temp[x], ',')))
		mlx_arr->map[y][x][1] = ft_atoi_base(temp[x], i + 3);
	else
		mlx_arr->map[y][x][1] = -1;
}

int			read_size(t_mlx *mlx_arr)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	if (0 > (fd = open(mlx_arr->file, O_RDONLY)))
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		line != NULL ? x += 1 : 0;
		ft_strdel(&line);
	}
	close(fd);
	free(line);
	mlx_arr->map_size[0] = x;
	return (x);
}

int			read_cordinates(t_mlx *mlx_arr, int fd, int x, int y)
{
	char	*line;
	char	**temp;

	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		temp = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (temp[x])
			x++;
		mlx_arr->map[y] = (int **)malloc(sizeof(int *) * x);
		x = 0;
		while (temp[x])
		{
			read_values(mlx_arr, temp, x, y);
			ft_strdel(&temp[x]);
			x += 1;
		}
		if (mlx_arr->map_size[1] != x && y != 0)
			return (-1);
		mlx_arr->map_size[1] = x;
		y += 1;
		free(temp);
	}
	return (0);
}

int			read_file(t_mlx *mlx_arr)
{
	int		y;
	int		x;
	int		fd;
	char	*line;

	if ((x = read_size(mlx_arr)) == -1)
		return (-1);
	mlx_arr->map = (int ***)malloc(sizeof(int **) * (x + 1));
	if (0 > (fd = open(mlx_arr->file, O_RDONLY)))
		return (-1);
	if (read_cordinates(mlx_arr, fd, 0, 0) == -1)
		return (-1);
	close(fd);
	return (0);
}
