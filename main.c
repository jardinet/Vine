/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:45:07 by mwragg            #+#    #+#             */
/*   Updated: 2019/03/21 16:26:33 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **argv)
{
	int fd;
	char *line;
	line = ft_strnew(3);
	if (ac == 2)
	{
		if((open(argv[1], O_RDONLY) = fd) > 0)
		{
			get_next_line(fd, &line);
			ft_putendl(line);
			return(1);
		}
		else
		{
			ft_putendl("uwu fuck up");
			return(0);
		}
		return(1);

	}
}
