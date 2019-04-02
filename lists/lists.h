/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:25:03 by mwragg            #+#    #+#             */
/*   Updated: 2019/03/29 15:23:41 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include "../Libft/libft.h"

typedef struct	s_inscrit
{
	char				*name[20];
	int					age;
	struct s_inscrit	*next;   //exemple of non-pre-prototyped structure !
}				t_inscrit;

typedef struct s_test t_test;

struct	s_test
{
	int		i;
	char	s[20];
	t_test	*next;     //exemple of previously prototyped structure !
};

#endif
