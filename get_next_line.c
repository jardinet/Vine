/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:43:01 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/09 22:58:32 by mwragg           ###   ########.fr       */
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

bufferisation
{
	ft_strnjoin_free(*line, c->buf +c->start, c->len, 1);
	if (c->start == (BUFF_SIZE -1))
		{
		c->ret = 0;
		c->len = 0;
		c->start = 0;
		}
	else
	{
	c->start = c->start +c->len +1;
	c->ret =
	}	
	//when len == BUFFSIZE -1 it's that buffer is empty
	//so bzero the boi and reset ret and len at 0;
	ft_strnjoin_free((**line), buf +c->start, c->len,  );
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*elem;
	t_list			*current;
	t_fd			*c;

	line = NULL;
	current = doesthisfdexist(fd, &elem);
	c = ((t_fd*)current->content);
	if (c->ret > 0)
	{
		if ((c->len != (BUFF_SIZE -1)) 
			&& ((c->len = ft_strichr(c->buf +c->len, CUT_CHAR)) == -1))
			ft_strjoin_free(*line, c->buf +c->len +1, 1);
		else
		{
			ft_strnjoin(*line, c->buf + 
			return qqchose;
		}
		bzero(buf, BUFF_SIZE);
	}
	while (((c->ret = read(c->fd, c->buf, BUFF_SIZE)) > 0)
			&& ((c->len = ft_strichr(buf, CUT_CHAR)) == -1))
		ft_strjoin_free(*line, buf);
	if (c->ret == -1)
		return (c->ret); //Error
	if (c->ret == 0)
	{
		delelem + content
			return (0); //EOF
	}
	//return (bufferisation());
	return(1); /*read line*/
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
			ft_putendl("Putting fd in for first time.");
			ft_putendl(ft_itoa(get_next_line(12, &line)));
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

