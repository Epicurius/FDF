/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@stuent.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:14:55 by nneronin          #+#    #+#             */
/*   Updated: 2019/10/18 15:31:22 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*asd;
	unsigned char	*qwe;

	asd = (unsigned char *)s1;
	qwe = (unsigned char *)s2;
	x = 0;
	while (n--)
	{
		if (asd[x] != qwe[x])
			return (asd[x] - qwe[x]);
		x++;
	}
	return (0);
}
