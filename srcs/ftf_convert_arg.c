/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf_convert_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:44:09 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/17 10:30:35 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		arg_signed_modifier(va_list ap, t_flags b)
{
	intmax_t	i;

	if (b.l == 1 || b.which_letter == 'D')
		i = (intmax_t)va_arg(ap, long);
	else if (b.h == 2)
		i = (intmax_t)(char)va_arg(ap, int);
	else if (b.h == 1)
		i = (intmax_t)(short)va_arg(ap, int);
	else if (b.l == 2)
		i = (intmax_t)va_arg(ap, long long);
	else if (b.j == 1)
		i = va_arg(ap, intmax_t);
	else if (b.z == 1)
		i = (intmax_t)va_arg(ap, ssize_t);
	else
		i = (intmax_t)va_arg(ap, int);
	return (i);
}

uintmax_t		arg_unsigned_modifier(va_list ap, t_flags b)
{
	uintmax_t	i;

	if (b.l == 1 || b.which_letter == 'U' || b.which_letter == 'O')
		i = (uintmax_t)va_arg(ap, unsigned long);
	else if (b.h == 2)
		i = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	else if (b.h == 1)
		i = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
	else if (b.l == 2)
		i = (uintmax_t)va_arg(ap, unsigned long long);
	else if (b.j == 1)
		i = va_arg(ap, uintmax_t);
	else if (b.z == 1)
		i = (uintmax_t)va_arg(ap, size_t);
	else
		i = (uintmax_t)va_arg(ap, unsigned int);
	return (i);
}
