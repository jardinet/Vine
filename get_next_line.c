/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:43:01 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/17 10:56:45 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

t_list	*doesthisfdexist(const int fd, t_list **elem)
{
	t_list	**head;
	t_fd	*fdcontent;

	head = elem;
	while (*head)
	{
		if (fd == ((t_fd *)(*head)->content)->fd)
			return (*head);
		head = &(*head)->next;
	}
	if ((fdcontent = (t_fd *)malloc(sizeof(t_fd))) == NULL)
		return (NULL);
	ft_bzero((void *)fdcontent, sizeof(t_fd));
	fdcontent->fd = fd;
	ft_lstadd(elem, ft_lstnew((void *)fdcontent, sizeof(t_fd)));
	free(fdcontent);
	return (*elem);
}

int		bufferisation(char **line, t_fd *c)
{
	if ((*line = ft_strnjoin_free(*line, c->buf + c->start, c->len, 1))
			== NULL)
		return (-1);
	c->start = c->start + c->len + 1;
	c->ret = c->ret - c->len;
	return (1);
}

int		from_read(char **line, t_fd *c)
{
	while (((c->ret = read(c->fd, c->buf, BUFF_SIZE)) > 0)
			&& (c->len = ft_strichr(c->buf, CUT_CHAR)) == -1)
	{
		if ((*line = ft_strjoin_free(*line, c->buf, 1)) == NULL)
			return (-1);
		bzero(c->buf, c->ret);
	}
	if (c->ret == 0 && *line != NULL && 0 != ft_strlen(*line))
		return (1);
	if (c->ret == -1)
		return (c->ret);
	if (c->ret == 0)
		return (0);
	return (bufferisation(line, c));
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*elem;
	t_list			*current;
	t_fd			*c;

	if (!line)
		return (-1);
	*line = NULL;
	if ((current = doesthisfdexist(fd, &elem)) == NULL)
		return (-1);
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
	return (from_read(line, c));
}
