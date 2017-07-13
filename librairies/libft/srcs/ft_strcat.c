/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:35:26 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:47:12 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(dest);
	while (src[count] != '\0')
	{
		dest[len] = src[count];
		len++;
		count++;
	}
	dest[len] = '\0';
	return (dest);
}
