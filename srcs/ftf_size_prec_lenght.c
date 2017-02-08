/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf_size_prec_lenght.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:01:54 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 14:59:12 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_size_prec(t_flags b, char *str)
{
	char		*tmp;

	tmp = (char *)malloc(sizeof(char) * (b.size_prec + 1));
	tmp = ft_memcpy(tmp, str, b.size_prec);
	tmp[b.size_prec] = '\0';
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

char			*ft_size_lenght(t_flags b, char *str)
{
	char		*tmp;
	int			len;

	len = b.size_lenght - ft_strlen(str) + 1;
	if (b.size_lenght <= (int)ft_strlen(str))
		return (str);
	else
	{
		tmp = (char *)malloc(sizeof(char) * (len));
		if (b.fill_w_zero == 1 && b.left_justify != 1)
			tmp = ft_memset(tmp, '0', b.size_lenght - ft_strlen(str));
		else
			tmp = ft_memset(tmp, ' ', b.size_lenght - ft_strlen(str));
		tmp[b.size_lenght - ft_strlen(str)] = '\0';
		if (b.left_justify == 1)
			str = ft_strjoin(str, tmp);
		else
			str = ft_strjoin(tmp, str);
		free(tmp);
	}
	return (str);
}

char			*ft_size_prec_int(t_flags b, char *str, int negative)
{
	char		*tmp;
	char		*tmp2;

	if (b.size_prec <= (int)ft_strlen(str) - negative)
		return (str);
	tmp = (char *)malloc(sizeof(char) * (b.size_prec - ft_strlen(str) + 1));
	tmp = ft_memset(tmp, '0', b.size_prec - ft_strlen(str));
	tmp[b.size_prec - ft_strlen(str)] = '\0';
	if (str[0] == '0' && str[1] == 'x' && b.which_letter == 'p')
	{
		tmp2 = str;
		str = ft_strjoin(tmp, &tmp2[2]);
		tmp2 = str;
		str = ft_strjoin("0x", tmp2);
		free(tmp2);
	}
	else
	{
		tmp2 = str;
		str = ft_strjoin(tmp, tmp2);
		free(tmp2);
	}
	free(tmp);
	return (str);
}

char			*ft_size_lenght_int(t_flags b, char *str)
{
	char		*tmp;

	if (b.size_lenght == 0)
		return (str);
	else if (b.size_lenght <= (int)ft_strlen(str))
		return (str);
	else
	{
		tmp = (char *)malloc(b.size_lenght - ft_strlen(str) + 1);
		if (b.fill_w_zero == 1 && b.left_justify != 1 && b.size_prec == -1)
			tmp = ft_memset(tmp, '0', b.size_lenght - ft_strlen(str));
		else
			tmp = ft_memset(tmp, ' ', b.size_lenght - ft_strlen(str));
		tmp[b.size_lenght - ft_strlen(str)] = '\0';
		str = ft_join_lenght_int(b, tmp, str);
		free(tmp);
	}
	return (str);
}
