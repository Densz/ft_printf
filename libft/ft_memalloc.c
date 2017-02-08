/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:22:47 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 15:39:55 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tmp;

	tmp = malloc(size);
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, 0, size);
	return (tmp);
}
