/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:56:17 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 15:43:38 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
