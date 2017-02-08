/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:23:39 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 18:17:13 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = 0;
	if (size == 0)
		return (j);
	while (src[k] != '\0' && i + k < size - 1)
	{
		dst[k + i] = src[k];
		k++;
	}
	dst[k + i] = '\0';
	if (i < size)
		return (j + i);
	else
		return (j + size);
}
