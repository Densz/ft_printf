/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:14:14 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/08 19:16:52 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			get_width(const char *s, int *i, t_flags b, va_list ap)
{
	b.size_lenght = va_arg(ap, int);
	if (b.size_lenght < 0)
	{
		b.size_lenght *= -1;
		b.left_justify = 1;
	}
	*i = *i + 1;
	return (b);
}

t_flags			get_precision(const char *s, int *i, t_flags b, va_list ap)
{
	*i = *i + 1;
	if (ft_isdigit(s[*i + 1]))
	{
		b.size_prec = ft_atoi(&s[*i + 1]);
		while (ft_isdigit(s[*i + 1]))
			*i = *i + 1;
	}
	else if (s[*i + 1] == '*')
	{
		b.size_prec = va_arg(ap, int);
		*i = *i + 1;
	}
	else
		b.size_prec = 0;
	return (b);
}
