/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:21:44 by mwragg            #+#    #+#             */
/*   Updated: 2016/12/06 15:27:12 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	nb;
	long int	nb2;
	size_t		i;
	char		*result;

	nb = (long)n;
	i = (n < 0) ? 1 : 0;
	nb = (n < 0) ? nb *= -1 : nb;
	nb2 = nb;
	while (nb > 9 && ++i)
		nb /= 10;
	if ((result = ft_strnew(i + 1)) == NULL)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	while (nb2 > 9)
	{
		result[i] = (nb2 % 10 + '0');
		i--;
		nb2 /= 10;
	}
	result[(n == 0 ? 0 : i)] = nb2 + '0';
	return (result);
}
