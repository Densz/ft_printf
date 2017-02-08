/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf_convert_to_o_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:33:44 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/17 10:42:35 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*convert_int_to_octal(uintmax_t i)
{
	uintmax_t	tmp;
	int			cnt;
	char		*str;

	tmp = i;
	cnt = 2;
	while ((tmp = tmp / 8) != 0)
		cnt++;
	if ((str = (char *)malloc(sizeof(char) * cnt)) == NULL)
		return (0);
	str[--cnt] = '\0';
	while (cnt-- > 0)
	{
		str[cnt] = i % 8 + '0';
		i = i / 8;
	}
	return (str);
}

int				ft_xvalue(uintmax_t i)
{
	if (i % 16 < 10)
		return (i % 16 + 48);
	if (i % 16 >= 10)
	{
		i = i - 10;
		return (i % 16 + 97);
	}
	return (0);
}

char			*convert_int_to_hex(uintmax_t i)
{
	char		*str;
	uintmax_t	tmp;
	int			cnt;

	tmp = i;
	cnt = 2;
	while ((tmp = tmp / 16) != 0)
		cnt++;
	if ((str = (char *)malloc(sizeof(char) * cnt)) == NULL)
		return (0);
	str[--cnt] = '\0';
	while (cnt-- > 0)
	{
		str[cnt] = ft_xvalue(i);
		i = i / 16;
	}
	return (str);
}

int				ft_xvalue_maj(uintmax_t i)
{
	if (i % 16 < 10)
		return (i % 16 + 48);
	if (i % 16 >= 10)
	{
		i = i - 10;
		return (i % 16 + 65);
	}
	return (0);
}

char			*convert_int_to_hex_maj(uintmax_t i)
{
	char		*str;
	uintmax_t	tmp;
	int			cnt;

	tmp = i;
	cnt = 2;
	while ((tmp = tmp / 16) != 0)
		cnt++;
	if ((str = (char *)malloc(sizeof(char) * cnt)) == NULL)
		return (0);
	str[--cnt] = '\0';
	while (cnt-- > 0)
	{
		str[cnt] = ft_xvalue_maj(i);
		i = i / 16;
	}
	return (str);
}
