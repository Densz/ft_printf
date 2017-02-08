/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:31:59 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 14:59:14 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_printf_c_maj(va_list ap, t_flags b)
{
	wchar_t		c;
	char		*str;
	int			len;
	int			i;

	str = NULL;
	i = 0;
	b.which_letter = 'C';
	c = va_arg(ap, wchar_t);
	if (c == 0)
	{
		if (b.size_lenght >= 2)
		{
			while (i++ < b.size_lenght - 1)
				ft_putchar(' ');
			b.size_lenght--;
		}
		ft_write_null();
		return (b.size_lenght + 1);
	}
	str = ft_unicode(c);
	str = ft_check_if_flags_str(b, str);
	len = ft_free_return(&str);
	return (len);
}

int				ft_printf_s_maj(va_list ap, t_flags b)
{
	wchar_t		*str;
	char		*out_unicode;
	int			len;

	b.which_letter = 'S';
	out_unicode = NULL;
	str = va_arg(ap, wchar_t *);
	if (str == NULL)
		out_unicode = ft_strdup("(null)");
	else
		out_unicode = ft_join_unicode(out_unicode, str);
	out_unicode = ft_check_if_flags_str(b, out_unicode);
	len = ft_free_return(&out_unicode);
	return (len);
}

int				ft_printf_c(va_list ap, t_flags b)
{
	char		c;
	char		*str;
	int			len;

	b.which_letter = 'c';
	if (b.l == 1)
		len = ft_printf_c_maj(ap, b);
	else
	{
		c = (char)va_arg(ap, int);
		if (c == 0)
		{
			if (b.size_lenght >= 2)
				ft_lenght_c(&b, &str);
			ft_write_null();
			return (b.size_lenght + 1);
		}
		str = ft_strchar(c, 1);
		str = ft_check_if_flags_str(b, str);
		len = ft_free_return(&str);
	}
	return (len);
}

int				ft_printf_s(va_list ap, t_flags b)
{
	char		*str;
	int			len;

	b.which_letter = 's';
	if (b.l == 1)
		len = ft_printf_s_maj(ap, b);
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
		{
			str = ft_strdup("(null)");
			str = ft_check_if_flags_str(b, str);
			len = ft_free_return(&str);
		}
		else
		{
			str = ft_check_if_flags_str(b, str);
			ft_putstr(str);
			len = ft_strlen(str);
		}
	}
	return (len);
}

int				ft_print_per_cent(t_flags b)
{
	char		*str;
	int			len;

	b.which_letter = '%';
	str = ft_strdup("%");
	str = ft_check_if_flags_str(b, str);
	if (b.size_prec == 0 && b.size_lenght != 0)
		str[ft_strlen(str) - 1] = '%';
	if (b.size_prec == 0 && b.size_lenght == 0)
		str = ft_strdup("%");
	len = ft_free_return(&str);
	return (len);
}
