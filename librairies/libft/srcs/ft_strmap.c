/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:12:58 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:48:28 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		count;
	char	*new_str;

	if (!s || !f || !(new_str = ft_strdup(s)))
		return (NULL);
	count = -1;
	while (new_str && new_str[++count])
		new_str[count] = f(new_str[count]);
	return (new_str);
}
