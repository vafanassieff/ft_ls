/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:54:31 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:47:57 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	len;
	int	count;

	if (!s || !f)
		return ;
	count = 0;
	len = ft_strlen(s);
	while (count < len)
	{
		f(s);
		s++;
		count++;
	}
}
