/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 02:59:24 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/16 17:26:56 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memdup(const char *s1, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = NULL;
	if ((dest = ((char *)malloc(sizeof(char) * (len)))) == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}
