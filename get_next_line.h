/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:19:09 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/14 22:35:45 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "./Libft/libft.h"
# define BUFF_SIZE 10

typedef struct	s_fd
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE];
	int		len;
}				t_fd;

int		get_next_line(const int fd, char **line);

#endif
