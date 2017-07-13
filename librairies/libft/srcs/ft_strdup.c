/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:35:53 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:47:41 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*sos;

	i = ft_strlen(src);
	sos = (char *)malloc(sizeof(char) * (i + 1));
	if (!sos)
		return (NULL);
	j = 0;
	while (j < i)
	{
		sos[j] = src[j];
		j++;
	}
	sos[j] = '\0';
	return (sos);
}
