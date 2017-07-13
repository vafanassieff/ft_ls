/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:00:35 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:49:03 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_s;

	if (!(new_s = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_strclr(new_s);
	return (new_s);
}
