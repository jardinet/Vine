/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:43:01 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/14 20:49:03 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

t_fd	*struct_init(const int fd)
{
	t_fd *fdcontent;

	if((fdcontent = (t_fd *)malloc(sizeof(t_fd))) == NULL)
		return (NULL);
	ft_bzero((void *)fdcontent, sizeof(t_fd));
	fdcontent->fd = fd;
	return (fdcontent);
}

t_list	*doesthisfdexist(const int fd, t_list **elem)
{
	t_list **head;

	head = elem;
	while (*head)
	{
		if (fd == ((t_fd *)(*head)->content)->fd )
			return (*head);
		head = &(*head)->next;
	}
	ft_lstadd(elem, ft_lstnew((void *)struct_init(fd), sizeof(t_fd)));
	return (*elem);
}

int		bufferisation(char **line, t_fd *c)
{
	if ((*line = ft_strnjoin_free(*line, c->buf +c->start, c->len, 1)) == NULL)
		return (-1);
	if (c->start > BUFF_SIZE -1)
		{
			ft_putendl("boucle start/buffsize)");
		c->ret = 0;
		c->len = 0;
		c->start = 0;
		}
	else
	{
		ft_putendl("updating new start/ret");
	ft_putnbr(c->ret);
	ft_putendl("RETURN VALUE");
	ft_putnbr(c->start);
	ft_putendl("START VALUE");
	c->start = c->start +c->len +1;
	c->ret = c->ret -c->len -1;
	ft_putnbr(c->ret);
	ft_putendl("RETURN VALUE");
	ft_putnbr(c->start);
	ft_putendl("START VALUE");
	}
	return(7);
	//when len == BUFFSIZE -1 it's that buffer is empty
	//so bzero the boi and reset ret and len at 0;
	//ft_strnjoin_free((**line), buf +c->start, c->len,  );
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*elem;
	t_list			*current;
	t_fd			*c;

	*line = NULL;
	current = doesthisfdexist(fd, &elem);
	c = ((t_fd*)current->content);
	if (c->ret > 0)
	{
	ft_putendl("bufer not empty");
		if ((c->len = ft_strichr(c->buf + c->start, CUT_CHAR)) == -1)
		{
			ft_putendl("full buff + no cut char");
			ft_putnbr(c->len);
			ft_putendl("len VALUE");
			if ((*line = ft_strjoin_free(*line, c->buf + c->start, 1)) == NULL)
				return (-1);
			bzero(c->buf, BUFF_SIZE);
			ft_putendl("boucle start/buffsize)");
			c->ret = 0;
			c->len = 0;
			c->start = 0;
		}
		else
		{
			ft_putendl("entering buferisation pre-read");
			return (bufferisation(line, c));
		}
	}
	while (((c->ret = read(c->fd, c->buf, BUFF_SIZE)) > 0)
			&& ((c->len = ft_strichr(c->buf, CUT_CHAR)) == -1))
		*line = ft_strjoin_free(*line, c->buf, 1);
	if (c->ret == -1)
		return (c->ret); //Error
	if (c->ret == 0)
	{
		ft_putendl("xd on verra apreees");
			return (0); //EOF
	}
	ft_putendl("entering buferisation post-read");
	return (bufferisation(line, c));
	return (126);
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
//			ft_putendl(ft_itoa(get_next_line(25, &line)));
//			ft_putendl("Putting 25 in for first time.");
//			ft_putendl(ft_itoa(get_next_line(25, &line)));
//			ft_putendl("Putting 25 in for second time.");
//			ft_putendl(ft_itoa(get_next_line(10, &line)));
//			ft_putendl("Putting 10 in for first time.");
//			ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
				ft_putendl(ft_itoa(get_next_line(fd, &line)));
				ft_putendl(line);
				ft_putendl("//////////////////////////");
//			ft_putendl("Putting 12 in for first time.");
//			ft_putendl(ft_itoa(get_next_line(13, &line)));
//			ft_putendl("Putting 13 in for first time.");
//			ft_putendl(ft_itoa(get_next_line(25, &line)));
//			ft_putendl("Putting 25 in for third time, after other numbers.");
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

