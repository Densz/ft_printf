/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:12:23 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/17 14:40:27 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_check_there_is_letter(char c)
{
	if (c == 's' || c == 'i' || c == 'd' ||
			c == 'c' || c == 'C' || c == 'o' ||
			c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'p' ||
			c == 'D' || c == 'S' || c == '%')
		return (1);
	else
		return (0);
}

int				ft_check_letter(va_list ap, char c, t_flags b)
{
	if (c == 's')
		return (ft_printf_s(ap, b));
	else if (c == 'i' || c == 'd' || c == 'D')
		return (ft_printf_i(ap, b, c));
	else if (c == '%')
		return (ft_print_per_cent(b));
	else if (c == 'c')
		return (ft_printf_c(ap, b));
	else if (c == 'C')
		return (ft_printf_c_maj(ap, b));
	else if (c == 'o' || c == 'O')
		return (ft_printf_o(ap, b, c));
	else if (c == 'u' || c == 'U')
		return (ft_printf_u(ap, b, c));
	else if (c == 'S')
		return (ft_printf_s_maj(ap, b));
	else if (c == 'x')
		return (ft_printf_x(ap, b));
	else if (c == 'X')
		return (ft_printf_x_maj(ap, b));
	else if (c == 'p')
		return (ft_printf_p(ap, b));
	else if (ft_isprint(c) == 1)
		return (ft_apply_width(b, c));
	return (0);
}

int				ft_is_flags(char c)
{
	if (c == '-' || c == '+' ||
		c == '#' || c == '0' || c == ' ')
		return (1);
	return (0);
}
