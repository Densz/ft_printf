/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf_check_if_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:25:57 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 14:37:12 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_is_blank(t_flags b, char *str, int negative)
{
	char	*tmp;

	if (negative == 1)
		return (str);
	if (b.is_blank == 1 && (b.which_letter == 'i' || b.which_letter == 'D'))
	{
		tmp = str;
		str = ft_strjoin(" ", tmp);
		free(tmp);
	}
	return (str);
}

char		*ft_is_pos_nul(t_flags b, char *str, int negative)
{
	char	*tmp;

	if (negative == 1)
		return (str);
	if (b.pos_nul == 1 && (b.which_letter == 'i' || b.which_letter == 'D'))
	{
		tmp = str;
		str = ft_strjoin("+", tmp);
		free(tmp);
	}
	return (str);
}

char		*ft_size_prec_unicode(t_flags b, char *str)
{
	int		nb_octet;
	int		offset;

	nb_octet = 0;
	offset = 0;
	while (offset + nb_octet <= b.size_prec)
	{
		offset += nb_octet;
		nb_octet = ft_check_strong_bite(str[offset]);
	}
	str[offset] = '\0';
	return (str);
}

char		*ft_check_if_flags_str(t_flags b, char *str)
{
	if (b.size_prec != -1 && b.which_letter == 'S')
		str = ft_size_prec_unicode(b, str);
	if (b.size_prec != -1 && b.which_letter != 'c' && b.which_letter != 'C')
		str = ft_size_prec(b, str);
	if (b.size_lenght != 0)
		str = ft_size_lenght(b, str);
	return (str);
}

char		*ft_check_if_flags_int(t_flags b, char *str)
{
	size_t	negative;
	char	*tmp;

	negative = 0;
	if (str[0] == '-')
	{
		negative = 1;
		str = ft_strncpy(str, &str[1], ft_strlen(str) - 1);
		str[ft_strlen(str) - 1] = '\0';
	}
	if (b.size_prec != -1)
		str = ft_size_prec_int(b, str, negative);
	if (negative == 1)
	{
		tmp = str;
		str = ft_strjoin("-", tmp);
		ft_memdel((void **)&tmp);
	}
	if (b.pos_nul == 1)
		str = ft_is_pos_nul(b, str, negative);
	else if (b.is_blank == 1 && b.pos_nul != 1)
		str = ft_is_blank(b, str, negative);
	str = ft_join_flags_int(b, str);
	return (str);
}
