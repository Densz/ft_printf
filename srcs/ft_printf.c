/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 10:22:35 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/08 19:54:41 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			ft_check_flags(char c, t_flags b)
{
	if (c == '-' || c == '+' || c == '#' || c == '0' || c == ' ')
	{
		if (c == '+')
			b.pos_nul = 1;
		if (c == '-')
			b.left_justify = 1;
		if (c == '#')
			b.is_sharp = 1;
		if (c == '0')
			b.fill_w_zero = 1;
		if (c == ' ')
			b.is_blank = 1;
		return (b);
	}
	return (b);
}

t_flags			ft_check_modifier(char c, char c2, t_flags b)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
	{
		if (c == 'h')
		{
			if (c2 == 'h')
				b.h++;
			b.h++;
		}
		if (c == 'l')
		{
			if (c2 == 'l')
				b.l++;
			b.l++;
		}
		if (c == 'j')
			b.j = 1;
		if (c == 'z')
			b.z = 1;
		return (b);
	}
	return (b);
}

t_flags			get_struct(const char *s, int *i, t_flags b, va_list ap)
{
	while (ft_is_flags(s[*i + 1]))
	{
		b = ft_check_flags(s[*i + 1], b);
		*i = *i + 1;
	}
	if (ft_isdigit(s[*i + 1]))
	{
		b.size_lenght = ft_atoi(&s[*i + 1]);
		while (ft_isdigit(s[*i + 1]))
			*i = *i + 1;
	}
	else if (s[*i + 1] == '*')
		b = get_width(i, b, ap);
	if (s[*i + 1] == '.')
		b = get_precision(s, i, b, ap);
	if (s[*i + 1] == 'h' || s[*i + 1] == 'l' ||
		s[*i + 1] == 'j' || s[*i + 1] == 'z')
	{
		b = ft_check_modifier(s[*i + 1], s[*i + 2], b);
		*i += ((b.h == 2 || b.l == 2) ? 2 : 1);
	}
	return (b);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;
	t_flags		b;
	int			len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		b = (t_flags){0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0};
		if (format[i] == '%')
		{
			b = get_struct(format, &i, b, ap);
			len = len + ft_check_letter(ap, format[i + 1], b);
			ft_isprint(format[i + 1]) ? i = i + 2 : i++;
		}
		else
		{
			write(1, &format[i++], 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
