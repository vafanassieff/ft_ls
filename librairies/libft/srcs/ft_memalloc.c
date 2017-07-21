/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:40:38 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/21 16:46:10 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int				i;
	unsigned char	*c;

	if (!(c = (unsigned char*)malloc(size)))
		return (NULL);
	i = 0;
	while (size--)
	{
		c[i] = 0;
		i++;
	}
	return ((void*)c);
}
