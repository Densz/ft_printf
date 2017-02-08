/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:38:42 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 14:58:35 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_printf_u(va_list ap, t_flags b, char c)
{
	char			*str;
	uintmax_t		i;
	int				len;

	b.which_letter = c;
	i = arg_unsigned_modifier(ap, b);
	if (i == 0 && b.size_prec == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_uintmax_t(i);
	str = ft_check_if_flags_int(b, str);
	len = ft_free_return(&str);
	return (len);
}

int					ft_printf_o(va_list ap, t_flags b, char c)
{
	char			*str;
	uintmax_t		i;
	int				len;

	b.which_letter = c;
	i = arg_unsigned_modifier(ap, b);
	if ((b.is_sharp == 1 && i == 0) ||
		(i == 0 && b.size_lenght == 0 && b.size_prec == -1))
		str = ft_strdup("0");
	else if (b.size_prec == 0 && i == 0)
	{
		str = ft_strdup("");
		str = ft_size_lenght_int(b, str);
	}
	else
	{
		str = NULL;
		str = ft_convert_octal(str, i, b);
	}
	len = ft_free_return(&str);
	return (len);
}

int					ft_printf_x(va_list ap, t_flags b)
{
	char			*str;
	uintmax_t		i;
	int				len;

	b.which_letter = 'x';
	i = arg_unsigned_modifier(ap, b);
	if (b.size_prec == 0 && i == 0)
	{
		str = ft_strdup("");
		str = ft_size_lenght_int(b, str);
	}
	else if (i == 0)
		str = ft_strdup("0");
	else
	{
		str = convert_int_to_hex(i);
		str = ft_check_if_flags_int(b, str);
	}
	len = ft_free_return(&str);
	return (len);
}

int					ft_printf_x_maj(va_list ap, t_flags b)
{
	char			*str;
	uintmax_t		i;
	int				len;

	b.which_letter = 'X';
	i = arg_unsigned_modifier(ap, b);
	if (b.size_prec == 0 && i == 0)
	{
		str = ft_strdup("");
		str = ft_size_lenght_int(b, str);
	}
	else if (i == 0)
		str = ft_strdup("0");
	else
	{
		str = convert_int_to_hex_maj(i);
		str = ft_check_if_flags_int(b, str);
	}
	len = ft_free_return(&str);
	return (len);
}
