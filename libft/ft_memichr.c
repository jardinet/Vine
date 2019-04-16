/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 03:06:36 by mwragg            #+#    #+#             */
/*   Updated: 2019/03/19 19:14:33 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memichr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && ((unsigned char*)s)[i] != (unsigned char)c)
		i++;
	if (i < n && ((unsigned char*)s)[i] == (unsigned char)c)
		return (i);
	return (-1);
}
