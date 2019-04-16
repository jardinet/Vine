/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:23:31 by mwragg            #+#    #+#             */
/*   Updated: 2016/12/13 16:38:02 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *temp;
	t_list *elem;

	if (!lst || (first = f(ft_lstnew(lst->content, lst->content_size))) == NULL)
		return (NULL);
	lst = lst->next;
	temp = first;
	while (lst != NULL)
	{
		elem = f(ft_lstnew(lst->content, lst->content_size));
		temp->next = elem;
		lst = lst->next;
		temp = elem;
	}
	return (first);
}
