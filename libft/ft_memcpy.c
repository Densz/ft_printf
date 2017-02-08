/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:20:38 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/02 14:17:33 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sorc;
	size_t	i;

	dest = (char *)dst;
	sorc = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}
