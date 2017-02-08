/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:17:20 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/29 15:01:46 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		negative;
	int		i;
	int		nb;

	i = 0;
	negative = 0;
	nb = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (negative == 1)
		return (-nb);
	else
		return (nb);
}
