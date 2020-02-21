/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:01:19 by nneronin          #+#    #+#             */
/*   Updated: 2020/02/21 19:39:32 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define RGB 1
# define START_SIZE 1
# define WIN_WIDTH 1920
# define WIN_HIGHT 1300

typedef struct		s_mlx
{
	double			cam[5];
	double			size[3];
	void			*win_ptr;
	void			*mlx_ptr;
	char			*file;
	int				win_size[2];
	int				map_size[2];
	int				mouse[2];
	int				rgb[6];
	int				***map;
	int				***vector;
	int				type;
	int				menu;
	int				press;
	int				c;
	int				c1;
	int				r;
	int				spectrum;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				xy[2];
	int				cath[2];
	int				overflow[2];
}					t_mlx;
/*
** Matrix Calculator
*/
void				calculate_paralel(t_mlx *mlx_arr, int dx, int dy);
void				calculate_iso(t_mlx *mlx_arr, int dx, int dy);
void				new_array(t_mlx *mlx_arr);
/*
** Print Image
*/
void				re_draw(t_mlx *mlx_arr);
void				image_to_win(t_mlx *mlx_arr, int y, int x);
void				image_clear(t_mlx *mlx_arr, int y, int x);
/*
** Color
*/
void				ft_rgb(t_mlx *mlx_arr);
int					ft_gradient(int *rgb, double i);
int					rainbow(t_mlx *mlx_arr, int a);
/*
** Rotation
*/
void				rotate_x(int *y, int *z, double i);
void				rotate_y(int *x, int *z, double i);
void				rotate_z(int *x, int *y, double i);
/*
** Controls
*/
int					key_press(int key, t_mlx *mlx_arr);
int					mouse_move(int x, int y, t_mlx *mlx_arr);
int					mouse_release(int key, int x, int y, t_mlx *mlx_arr);
int					mouse_press(int key, int x, int y, t_mlx *mlx_arr);
/*
**	Extra functions
*/
void				line(t_mlx *mlx_arr);
void				fill(t_mlx *mlx_arr, int x1, int y2, int color);
void				info(t_mlx *mlx_arr);
int					read_file(t_mlx *mlx_arr);
int					ft_atoi_base(char *str, int y);

#endif
