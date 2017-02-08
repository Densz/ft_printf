/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:12:08 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/02 15:01:55 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*big1;
	char	*little1;

	i = 0;
	j = 0;
	little1 = (char *)little;
	big1 = (char *)big;
	if (little1[j] == '\0')
		return (big1);
	while (big1[i] != '\0')
	{
		j = 0;
		if (big1[i] == little1[j])
		{
			while (big1[i + j] == little1[j] && big1[i + j])
			{
				if (little1[++j] == '\0')
					return (&big1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
