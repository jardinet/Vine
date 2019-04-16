/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:26:00 by mwragg            #+#    #+#             */
/*   Updated: 2016/11/30 20:42:39 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimed;
	size_t	i;
	size_t	j;

	if (!s || s == 0)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == j + 1)
		i = 0;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (trimed = ft_strsub(s, i, j - i + 1));
}
