/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingdoublepointeurlist.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:48:48 by mwragg            #+#    #+#             */
/*   Updated: 2019/04/01 18:00:26 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_test *init_struct(int c, char *s)
{
	t_test *t;

	t = malloc(sizeof(t_test));
	t->i = c;
	ft_strcpy(t->s, s);
	return (t);
}

int main(int ac, char **av)
{
	t_test *t;
	t_test **d;

	t = init_struct(13, "yolo");
	d = malloc(sizeof(*d));
	*d = t;
	ft_putstr("Le bail avec t->s:\t ");
	ft_putendl(t->s);
	ft_putstr("Le bail de *t.s:\t ");
	ft_putendl((*t).s);
	ft_putstr("Le bail avec (*d)->s:\t ");
	ft_putendl((*d)->s);
	ft_putstr("Le bail de (*(*d)).s:\t ");
	ft_putendl((*(*d)).s);
	return (0);
}
	// *d->s c'est la meme que *(*d).s
