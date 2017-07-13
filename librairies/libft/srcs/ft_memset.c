/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:01:55 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:46:08 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char k;
	unsigned char *i;

	k = (unsigned char)c;
	i = (unsigned char *)b;
	while (len--)
		*i++ = k;
	return (b);
}
