/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:01:47 by mwragg            #+#    #+#             */
/*   Updated: 2016/12/07 13:02:50 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsubtab(char **s, unsigned int start, size_t len)
{
	char **section;

	if (!s ||
		(section = (char **)ft_memalloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	section = ft_strncpytab(section, (char **)s + start, len);
	section[len] = NULL;
	return (section);
}
