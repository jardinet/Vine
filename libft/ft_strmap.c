/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:05:31 by mwragg            #+#    #+#             */
/*   Updated: 2016/12/05 16:54:40 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	i = 0;
	if ((!s || !(*f)) || ((new = ft_strdup(s)) == NULL))
		return (NULL);
	while (new[i])
	{
		new[i] = f(new[i]);
		i++;
	}
	return (new);
}
