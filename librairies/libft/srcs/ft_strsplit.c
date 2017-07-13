/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 14:59:11 by vafanass          #+#    #+#             */
/*   Updated: 2016/11/15 15:49:21 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int nb_word;

	nb_word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			nb_word += 1;
			while (*s && *s != c)
				s++;
		}
	}
	return (nb_word);
}

static char		*ft_dword(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(word = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbw;
	int		i;

	if (!s || !c)
		return (NULL);
	nbw = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * nbw + 1)))
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			tab[++i] = ft_dword(s, c);
		while (*s && *s != c)
			s++;
	}
	tab[nbw] = NULL;
	return (tab);
}
