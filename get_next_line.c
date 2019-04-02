/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:43:01 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/02 23:43:04 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

/*get_fd();*/

t_fd	*struct_init(const int fd)
{
	t_fd *fdcontent;

	if((fdcontent = (t_fd *)malloc(sizeof(t_fd))) == NULL)
		return (NULL);
	ft_bzero((void *)fdcontent, sizeof(t_fd));
	fdcontent->fd = fd;
//	ft_putendl("hi just checking the strcpy");
	ft_strcpy(fdcontent->buf, "hi does");
//	ft_putstr(fdcontent->buf);
//	ft_putnbr(fdcontent->len);
	return (fdcontent);
}

t_list	*doesthisfdexist(const int fd, t_list **elem, int *i)
{
	t_list **head;

	head = elem;
	while (*head)
	{
		(*i)++;
		ft_putendl("hi i'm passing through, option 1.");
		if (fd == ((t_fd *)(*head)->content)->fd )
			return (*head);
		*head = (*head)->next;
	}
	ft_putendl("yes you do get here, option 2");
	ft_lstadd(elem, ft_lstnew((void *)struct_init(fd), sizeof(t_fd)));
		(*i)++;
	return (*elem);
}

void	print_list(t_list *elem, int *i)
{
	while (elem)
	{
		ft_putstr("THIS IS EDITION ");
		ft_putnbr((*i));
		ft_putendl(".");
		ft_putstr("Maillon n*");
		ft_putnbr(*i);
		ft_putendl(" :");
		ft_putnbr(((t_fd *)elem->content)->fd);
		ft_putendl("FD ok?");
		ft_putnbr(((t_fd *)elem->content)->ret);
		ft_putendl("Ret ok?");
		ft_putstr(((t_fd *)elem->content)->buf);
		ft_putendl("buf ok?");
		ft_putnbr(ft_strlen(((t_fd *)(elem->content))->buf));
		ft_putendl("putnbr du buf ok?");
		ft_putnbr(((t_fd *)elem->content)->len);
		ft_putendl("len ok?");
		elem = elem->next;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_list *elem;
	int i;

	i = 0;
	line = NULL;
	ft_putendl("\nWELCOME TO GNL 01.04.2019");
	print_list(doesthisfdexist(fd, &elem, &i), &i);
	ft_putnbr(sizeof(t_fd));
	ft_putendl("<= sizeof t_fd value");

	return(1); /*read line*/
	return(0); /*EOF*/
	return(-1); /*Error*/
}

int		main(int ac, char **argv)
{
	int fd;
	char *line;
	line = ft_strnew(3);
	ft_memset(line, 'a', 3);
	if (ac == 2)
	{
		if((fd = open(argv[1], O_RDONLY)) > 0)
		{
			ft_putendl(ft_itoa(get_next_line(25, &line)));
			ft_putendl(ft_itoa(get_next_line(25, &line)));
			ft_putendl(ft_itoa(get_next_line(10, &line)));
			ft_putendl(ft_itoa(get_next_line(fd, &line)));
			ft_putendl(ft_itoa(get_next_line(12, &line)));
			ft_putendl(ft_itoa(get_next_line(13, &line)));
			ft_putendl(ft_itoa(get_next_line(13, &line)));
			ft_putendl("^GNL return value.");
			return(1);
		}
		else
		{
			ft_putendl("uwu fuck up");
			return(-1);
		}
	}
		return(1);

}

