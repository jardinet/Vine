/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:15:34 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/05 20:37:57 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "./Libft/libft.h"
#define BUFF_SIZE 20

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char *link;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		link = ft_strdup(s2);
	else if (!s2)
		link = ft_strdup(s1);
	else
	{
		if ((link = (char *)malloc(sizeof(char) *
						(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
			return (NULL);
		link = ft_strcat(ft_strcpy(link, s1), s2);
	}
	free (s1);
	free (s2);
	return (link);
}

int		main(int ac, char **argv)
{
	int fd;
	int ret;
	char buf[BUFF_SIZE];
	char *line;

	if (ac == 2)
	fd = open(argv[1], O_RDONLY);
	while (((ret = read(fd, buf, BUFF_SIZE)) > 0)
			&& (ft_strichr(buf, '\n') == -1))
		ft_strjoin_free(line, buf);            

	if (ret == -1)
		return (-1);
}
