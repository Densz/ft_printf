/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:00:05 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/01 15:44:05 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	int		i;

	i = 0;
	t = (char *)s;
	while (t[i])
		i++;
	if (t[i] == (char)c)
		return (&t[i]);
	i--;
	while (t[i])
	{
		if (t[i] == (char)c)
			return (&t[i]);
		i--;
	}
	return (NULL);
}
