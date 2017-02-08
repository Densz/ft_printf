/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf_itoa_max_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:12:07 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/17 10:45:14 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void				n_isnegative(intmax_t *n, int *is_negative)
{
	if (*n < 0)
	{
		*is_negative = 1;
		*n = *n * -1;
	}
}

char					*ft_itoa_intmax_t(intmax_t n)
{
	int					i;
	char				*str;
	int					is_negative;
	intmax_t			tmp;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
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

char					*ft_itoa_uintmax_t(uintmax_t n)
{
	int					i;
	char				*str;
	uintmax_t			tmp;

	i = 2;
	tmp = n;
	while ((tmp = tmp / 10) != 0)
		i++;
	if ((str = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	str[--i] = '\0';
	while (i-- > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
