/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 03:14:08 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/16 17:28:05 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memsub(char const *s, unsigned int start, size_t len)
{
	char *section;

	if (!s || (section = ((char *)malloc(sizeof(char) * (len)))) == NULL)
		return (NULL);
	section = ft_memncpy(section, (char *)s + start, len);
	return (section);
}
