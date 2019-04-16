/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:19:09 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/16 20:59:07 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 25
# define CUT_CHAR '\n'

typedef struct	s_fd
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	int			len;
	int			start;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
