/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:13:37 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 14:27:11 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_xvalue(unsigned long *i)
{
	int				ret;

	if (*i % 16 < 10)
	{
		ret = *i % 16 + 48;
		*i = *i / 16;
		return (ret);
	}
	if (*i % 16 >= 10 && *i % 16 <= 16)
	{
		*i = *i - 10;
		ret = *i % 16 + 97;
		*i = *i / 16;
		return (ret);
	}
	ret = 0;
	*i = *i / 16;
	return (ret);
}

int					ft_printf_p(va_list ap, t_flags b)
{
	unsigned long	i;
	char			*str;
	unsigned long	tmp;
	int				cnt;

	b.which_letter = 'p';
	i = (unsigned long)va_arg(ap, void *);
	if (i == 0 && b.size_prec > -1)
		str = ft_strdup("");
	else
	{
		tmp = i;
		cnt = 2;
		while ((tmp = tmp / 16) != 0)
			cnt++;
		if (!(str = (char *)malloc(sizeof(char) * cnt)))
			return (0);
		str[--cnt] = '\0';
		while (cnt-- > 0)
			str[cnt] = ft_xvalue(&i);
	}
	cnt = ft_free_flags_return(&str, b);
	return (cnt);
}
