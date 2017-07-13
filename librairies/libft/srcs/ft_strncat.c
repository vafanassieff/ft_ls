/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:47:47 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:48:39 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		count;
	int		len;
	size_t	kek;

	count = 0;
	kek = 0;
	len = ft_strlen(dest);
	while (kek < n && src[count])
	{
		dest[len] = src[count];
		len++;
		count++;
		kek++;
	}
	dest[len] = '\0';
	return (dest);
}
