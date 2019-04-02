/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:45:47 by mwragg            #+#    #+#             */
/*   Updated: 2019/03/19 18:46:26 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <fcntl.h>

int		main(int ac, char **argv)
{
	int fd;
	int fd2;
	int ret;
	int ret2;
	char buf[40];
	char buf2[40];

	if (ac == 5)
	{
		/**if (ft_memcmp(argv[4], "f", 1) == 0)*/
		if (argv[4][0] == 'f' && !argv[4][1])
		{
			ft_putendl("Let's open the files.");
			fd = open(argv[1], O_RDWR);
			fd2 = open(argv[2], O_RDWR);
			ft_putendl("Let's read the files.");
			ret = read(fd, buf, ft_atoi(argv[3]));
			ret2 = read(fd2, buf2, ft_atoi(argv[3]));
			ft_putendl("Let's compare the files.");
			ft_putnbr(ft_memcmp(buf, buf2, ft_atoi(argv[3])));
		}
		/*if (ft_memcmp(argv[4], "s", 1) == 0)*/
		if (argv[4][0] == 's' && !argv[4][1])
		{
			ft_putendl("Let's compare the strings");
			ft_putnbr(ft_memcmp(argv[1], argv[2], ft_atoi(argv[3])));
		}
	}
	return(0);
}
