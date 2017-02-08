/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:24:52 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/02 15:37:14 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		n_isnegative(int *n, int *is_negative)
{
	if (*n < 0)
	{
		*is_negative = 1;
		*n = *n * -1;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		is_negative;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 2;
	is_negative = 0;
	tmp = n;
	n_isnegative(&n, &is_negative);
	while ((tmp = tmp / 10) != 0)
		i++;
	i = i + is_negative;
	if ((str = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	str[--i] = '\0';
	while (i-- > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (is_negative == 1)
		str[0] = '-';
	return (str);
}
