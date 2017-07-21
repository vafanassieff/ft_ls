/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:01:55 by vafanass          #+#    #+#             */
/*   Updated: 2017/07/21 16:45:48 by vafanass         ###   ########.fr       */
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
