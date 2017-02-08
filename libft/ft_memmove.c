/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:57:29 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 15:50:30 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	i = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	if (src2 < dst2)
	{
		while ((int)--len >= 0)
			dst2[len] = src2[len];
	}
	else
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst2);
}
