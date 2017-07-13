/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:04:22 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:55:32 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new_s;

	if (!s1 || !s2 || !(new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	new_s = ft_strcpy(new_s, s1);
	new_s = ft_strcat(new_s, s2);
	new_s[ft_strlen(new_s)] = '\0';
	return (new_s);
}
