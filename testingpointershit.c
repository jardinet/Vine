/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingpointershit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:36:06 by mwragg            #+#    #+#             */
/*   Updated: 2019/03/18 17:13:32 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

void	main(void)
{
	char *str;
	char *str2;

	ft_memset((str = ft_strnew(10)), 'a', 5);
	ft_putendl(str);
	ft_memset((str2 = ft_strnew(10)), 'b', 5);
	ft_putendl(str2);
	ft_putendl(str2 = str + 2);
	ft_putnbr(str-str2);
}
