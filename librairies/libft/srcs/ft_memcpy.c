/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:33:48 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/21 12:28:56 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (dst == NULL && src == NULL)
		return (NULL);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	while (n--)
		*a++ = *b++;
	return (dst);
}
