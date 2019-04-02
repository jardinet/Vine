/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coucou.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:08:37 by mwragg            #+#    #+#             */
/*   Updated: 2019/03/26 19:24:22 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"

typedef struct s_inscrit	t_inscrit;

typedef struct		s_inscrit
{
	char	name[20];
	int		age;
	t_inscrit *next;
}					t_inscrit;

t_inscrit*	ft_newlist(void)
{
	t_inscrit *new;

	if ((new = (t_inscrit *)malloc(sizeof(t_inscrit))) == NULL)
		return (NULL);

	return(new);
}

void	ft_add_members(t_inscrit **firstelem, char *nom, int age)
{
	t_inscrit *new;
	t_inscrit *temp;
	t_inscrit *before;

	if ((new = ft_newlist()) == NULL)
		return;
	ft_strcpy(new->name, nom);
	new->age = age;
	temp = *firstelem; /*ALED ICI*/
//	before = *firstelem;
	before = NULL;
	while (temp && new->age > temp->age) /*ALED ICI*/
	{
		before = temp;
		temp = temp->next;
	}
	if (before)
		before->next = new;
	else
		*firstelem = new;


	new->next = temp;
}

void	ft_print_list(t_inscrit *elem)
{
	while (elem)
	{
		ft_putstr(elem->name);
		ft_putnbr(elem->age);
		elem = elem->next;
	}
}

int		main(void)
{
	t_inscrit *firstelem;

	firstelem = NULL;
	ft_add_members(&firstelem, "Marc", 12);
	ft_add_members(&firstelem, "Jade", 13);
	ft_add_members(&firstelem, "Felix", 22);
	ft_add_members(&firstelem, "Marie", 23);
	ft_print_list(firstelem);

}
