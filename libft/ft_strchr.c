/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:39:00 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/01 15:43:24 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;
	int		i;

	i = 0;
	t = (char *)s;
	while (t[i])
	{
		if (t[i] == (char)c)
			return (&t[i]);
		i++;
	}
	if (t[i] == (char)c)
		return (&t[i]);
	return (NULL);
}
