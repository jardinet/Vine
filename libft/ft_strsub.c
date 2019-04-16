/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:27:00 by mwragg            #+#    #+#             */
/*   Updated: 2016/11/30 17:25:51 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *section;

	if (!s || (section = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	section = ft_strncpy(section, (char *)s + start, len);
	section[len] = '\0';
	return (section);
}
