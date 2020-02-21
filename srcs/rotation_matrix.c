/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:26:56 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/19 14:27:46 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double i)
{
	int tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(i) + *z * sin(i);
	*z = -tmp_y * sin(i) + *z * cos(i);
}

void	rotate_y(int *x, int *z, double i)
{
	int tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(i) + *z * sin(i);
	*z = -tmp_x * sin(i) + *z * cos(i);
}

void	rotate_z(int *x, int *y, double i)
{
	int tmp_x;
	int tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(i) - tmp_y * sin(i);
	*y = tmp_x * sin(i) + tmp_y * cos(i);
}
