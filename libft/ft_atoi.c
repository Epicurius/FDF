/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@stuent.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:26:46 by nneronin          #+#    #+#             */
/*   Updated: 2019/10/26 15:42:12 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	x;
	int	negative;

	result = 0;
	x = 0;
	negative = 1;
	if (!str[x])
		return (0);
	while (!ft_isprint(str[x]) || str[x] == ' ' || str[x] == '+')
	{
		if (str[x] == '+' || str[x] == 27)
			if (str[x + 1] == '+' || str[x + 1] == '-' || str[x] == 27)
				return (0);
		x++;
	}
	negative *= str[x] == '-' ? -1 : 1;
	x += negative == -1 ? 1 : 0;
	while (str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10 + (str[x] - '0');
		x++;
	}
	return (result * negative);
}
