/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:01:35 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 18:11:52 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	if (str2 == NULL)
		return ;
	while (str2[i])
	{
		ft_putchar_fd(str2[i], fd);
		i++;
	}
}
