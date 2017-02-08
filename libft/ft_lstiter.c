/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:30:06 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 13:47:57 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next1;

	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		next1 = lst->next;
		f(lst);
		lst = next1;
	}
}
