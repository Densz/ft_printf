/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:02:26 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 14:52:36 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_join_unicode(char *out_unicode, wchar_t *str)
{
	char	*to_add;
	char	*tmp;

	out_unicode = ft_strdup("");
	while (*str)
	{
		if ((to_add = ft_unicode(*str)) == NULL)
			return (0);
		tmp = out_unicode;
		out_unicode = ft_strjoin(out_unicode, to_add);
		free(tmp);
		free(to_add);
		str++;
	}
	return (out_unicode);
}

char		*ft_convert_octal(char *str, uintmax_t i, t_flags b)
{
	char	*tmp;

	str = convert_int_to_octal(i);
	if (str[0] == '-')
		str = ft_strdup(&str[1]);
	if (b.is_sharp == 1)
	{
		tmp = str;
		str = ft_strjoin("0", tmp);
		free(tmp);
	}
	str = ft_check_if_flags_int(b, str);
	return (str);
}

char		*ft_join_flags_int(t_flags b, char *str)
{
	char	*tmp;

	if ((b.is_sharp == 1 && b.which_letter == 'x') || b.which_letter == 'p')
	{
		tmp = str;
		str = ft_strjoin("0x", tmp);
		ft_memdel((void **)&tmp);
	}
	if (b.is_sharp == 1 && b.which_letter == 'X')
	{
		tmp = str;
		str = ft_strjoin("0X", tmp);
		ft_memdel((void **)&tmp);
	}
	if (b.size_lenght != 0)
		str = ft_size_lenght_int(b, str);
	return (str);
}

char		*ft_join_lenght_int(t_flags b, char *tmp, char *str)
{
	char	*tmp2;

	if (b.left_justify == 1)
	{
		tmp2 = str;
		str = ft_strjoin(tmp2, tmp);
		free(tmp2);
	}
	else
	{
		tmp2 = str;
		str = ftf_join_flags(tmp2, b, tmp);
		free(tmp2);
	}
	return (str);
}
