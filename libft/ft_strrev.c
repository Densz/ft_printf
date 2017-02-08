/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:47:32 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 17:05:31 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len = len - 1;
	while (i < len)
	{
		tmp = str[len];
		str[len] = str[i];
		str[i] = tmp;
		len--;
		i++;
	}
	return (str);
}
