/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:17:57 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 11:54:43 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	if (del == NULL)
		return ;
	while (tmp != NULL)
	{
		next = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
