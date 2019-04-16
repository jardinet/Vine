/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:24:29 by mwragg            #+#    #+#             */
/*   Updated: 2016/11/22 14:31:27 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t tmp;
	size_t j;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[0])
		{
			tmp = i;
			while (little[j] && big[i] == little[j] && i < len)
			{
				j++;
				i++;
			}
			if (j == ft_strlen(little))
				return ((char*)big + tmp);
			i = tmp;
		}
		i++;
	}
	return (NULL);
}
