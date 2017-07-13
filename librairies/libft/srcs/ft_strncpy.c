/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:04:51 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:48:52 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*subd;

	if (!n)
		return (dest);
	subd = dest;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n)
	{
		*dest++ = '\0';
		n--;
	}
	return (subd);
}
