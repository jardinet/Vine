/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:43:01 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/15 13:41:30 by mwragg           ###   ########.fr       */
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
	if ((*line = ft_strnjoin_free(*line, c->buf +c->start, c->len +1, 1)) == NULL)
		return (-1);
	if (c->start > BUFF_SIZE -1)
		{
		c->ret = 0;
		c->len = 0;
		c->start = 0;
		}
	else
	{
	c->start = c->start +c->len +1;
	c->ret = c->ret -c->len;
	}
	return(1);
}

void	del(void *ptr, size_t size)
{

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
		if ((c->len = ft_strichr(c->buf + c->start, CUT_CHAR)) == -1)
		{
			if ((*line = ft_strjoin_free(*line, c->buf + c->start, 1)) == NULL)
				return (-1);
			bzero(c->buf, BUFF_SIZE);
			c->ret = 0;
			c->len = 0;
			c->start = 0;
		}
		else
			return (bufferisation(line, c));
	}
	while (((c->ret = read(c->fd, c->buf, BUFF_SIZE)) > 0)
			&& ((c->len = ft_strichr(c->buf, CUT_CHAR)) == -1))
		*line = ft_strjoin_free(*line, c->buf, 1);
	if (c->ret == -1)
		return (c->ret); //Error
	if (c->ret == 0)
			return (0); //EOF
	}
	return (bufferisation(line, c));
	return (126);
}

int		main(int ac, char **argv)
{
	int fd;
	char *line;
	//line = ft_strnew(3);
	//ft_memset(line, '0', 3);
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
			while (get_next_line(fd, &line) != 0)
			{
				ft_putstr(line);
				free(line);
			}
			while (1){};
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

