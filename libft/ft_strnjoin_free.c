/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:43:33 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/11 22:00:42 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char const *s1, char const *s2, size_t len, int f)
{
	char *link;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		link = ft_strsub(s2, 0, len);
	else if (!s2)
		link = ft_strsub(s1, 0, len);
	else
	{
		if ((link = (char *)malloc(sizeof(char) *
						(ft_strlen(s1) + len + 1))) == NULL)
			return (NULL);
		link = ft_strncat(ft_strcpy(link, s1), s2, len);
	}
	if (f == 1 || f == 0)
		free((void *)s1);
	if (f == 2 || f == 0)
		free((void *)s2);
	return (link);
}
