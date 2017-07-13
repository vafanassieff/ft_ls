/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:10:54 by vafanass          #+#    #+#             */
/*   Updated: 2016/12/14 12:11:09 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		n;
	int		p;
	char	temp;

	n = 0;
	p = 0;
	while (str[n] != '\0')
		n++;
	n--;
	while (n > p)
	{
		temp = str[p];
		str[p] = str[n];
		str[n] = temp;
		p++;
		n--;
	}
	return (str);
}
