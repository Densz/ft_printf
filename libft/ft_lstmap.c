/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:57:08 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 15:36:44 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list2;

	if (f != NULL && lst != NULL)
	{
		list2 = f(lst);
		if (list2 != NULL && lst->next != NULL)
			list2->next = ft_lstmap(lst->next, f);
		return (list2);
	}
	return (NULL);
}
