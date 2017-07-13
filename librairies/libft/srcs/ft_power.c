/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:44:41 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:46:13 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int p)
{
	int	tmp;

	tmp = nb;
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	while (p > 1)
	{
		nb = nb * tmp;
		p--;
	}
	return (nb);
}
