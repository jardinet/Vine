/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:41:36 by mwragg            #+#    #+#             */
/*   Updated: 2019/03/08 20:48:51 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "./Libft/libft.h"
#define BUFF_SIZE 10

int		main(int ac, char **argv)
{
	int fd;
	int fd2;
	int ret;
	int ret2;
	char buf[40];
	char buf2[40];

	if (ac == 3)
	ft_putendl("Files are to be opened");
	fd = open(argv[1], O_RDONLY);
	ft_putnbr(fd);
	ft_putstr("\n");
	fd2 = open(argv[2], O_RDONLY);
	ft_putnbr(fd2);
	ft_putstr("\n");
	ft_putendl("Let's read !");
	ft_putstr("\n");
	if((ret = read(fd, buf, BUFF_SIZE)) != -1)
		{
		ft_putendl("Reading files was successful.");
		ft_putnbr(ret);
		ft_putstr("\n");
		}
	else
		ft_putendl("didntworkxd");
}
