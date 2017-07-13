/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:53:07 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:43:02 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_puissance(int n, int p, int nb)
{
	if (nb < 0)
		p = p - 1;
	while (p-- > 1)
		n = n * 10;
	return (n);
}

static	int		ft_intlen(int nb)
{
	int count;

	count = 1;
	if (nb >= 0)
	{
		count = 0;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		len;
	int		count;
	int		poids;
	char	*ret;

	len = ft_intlen(n);
	poids = 1;
	poids = ft_puissance(poids, len, n);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	count = 0;
	if (n < 0)
	{
		ret[count] = '-';
		count++;
	}
	if (n > 0)
		n = -n;
	while (poids >= 1)
	{
		ret[count++] = -(n / poids % 10) + 48;
		poids = poids / 10;
	}
	ret[count] = '\0';
	return (ret);
}
