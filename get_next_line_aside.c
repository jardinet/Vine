/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:16:22 by mwragg            #+#    #+#             */
/*   Updated: 2017/05/30 16:59:01 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*link;

	if ((!s1 || !s2) || (link = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	link = ft_strcat(ft_strcpy(link, s1), s2);
	free(s1);
	return (link);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUF_SIZE];
	int		ret;

	*line = ft_memset(*line, '\0', 1);
		while ((ret = (read(fd, buf, BUF_SIZE)) != -1) 
			|| (ft_strchr(buf, '\n') != NULL))
	{
		*line = ft_strjoin_free(*line, buf);
	}
	if (ret != -1)
	{

	}

	
}

int		main(int ac, char **argv)
{
	int		fd;
	char	*line;

	if (fd = open(argv[1], O_RDONLY))
		get_next_line(fd, &line);
	return(0);
}
