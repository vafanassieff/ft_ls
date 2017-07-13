/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:41:05 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:47:06 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int coucou;

	coucou = 1;
	while (coucou * coucou < nb)
		coucou++;
	if (coucou * coucou == nb)
		return (coucou);
	else
		return (0);
}
