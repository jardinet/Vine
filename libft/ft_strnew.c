/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 23:38:27 by mwragg            #+#    #+#             */
/*   Updated: 2016/11/28 23:45:48 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	if ((mem = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	ft_memset(mem, '\0', size + 1);
	return (mem);
}
