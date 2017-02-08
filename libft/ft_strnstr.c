/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:10:04 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/02 15:15:24 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big;
	char	*little;

	i = 0;
	j = 0;
	big = (char *)a;
	little = (char *)b;
	if (little[j] == '\0')
		return (big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && big[i + j] && i + j < len)
				j++;
			if (little[j] == '\0')
				return (&big[i]);
		}
		i++;
	}
	return (NULL);
}
