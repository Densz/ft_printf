/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:01:41 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/17 15:58:32 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		count;
	char	*dup;
	char	*str2;

	i = 0;
	count = 0;
	str2 = (char *)str;
	while (str2[count])
		count++;
	dup = (char *)malloc(sizeof(*str2) * (count + 1));
	if (dup == NULL)
		return (0);
	while (str2[i])
	{
		dup[i] = str2[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
