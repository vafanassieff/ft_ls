/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:34:23 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:49:31 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		count;

	if (!s || !(str = ft_strnew(len)))
		return (NULL);
	count = 0;
	while (len--)
	{
		str[count] = s[start];
		count++;
		start++;
	}
	str[count] = '\0';
	return (str);
}
