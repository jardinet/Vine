/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:48:55 by mwragg            #+#    #+#             */
/*   Updated: 2016/12/07 18:43:56 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	iw;
	size_t	nbl;
	size_t	i;
	size_t	j;

	if (!s || (tab = (char **)ft_memalloc(sizeof(char *) *
		(ft_count_words(s, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	nbl = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			iw = i;
		while (s[i] && s[i] != c && ++i)
			nbl++;
		if (nbl != 0)
			tab[j++] = ft_strsub(s, iw, nbl);
		nbl = 0;
	}
	return (tab);
}
