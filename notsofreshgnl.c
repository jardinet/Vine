/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:41:36 by mwragg            #+#    #+#             */
/*   Updated: 2019/03/21 12:02:30 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "./Libft/libft.h"
#define BUFF_SIZE 10

int		get_next_line(const int fd, char **line)
{
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
	return(1); /*read line*/
	return(0); /*EOF*/
	return(-1); /*Error*/
}



int		main(int ac, char **argv)
{
	int fd;
	char *line;
	int ret;

	ret = 12;
	if (ac < 2)
		ft_putendl("One file or more available.");
	fd = open(argv[1], O_RDONLY);
	ft_putendl("One or more files successfully opened.");
	if((ret = get_next_line(fd, &line)) == -1)
		ft_putendl("Error.");
	else if(ret == 1)
		ft_putendl("Line was read.");
	else if(ret == 0)
		ft_putendl("Reached end of file.");
	ft_putnbr(ret);
}
