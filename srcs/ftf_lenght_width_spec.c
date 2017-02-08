/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftf_lenght_width_spec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:45:21 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 11:57:39 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_lenght_c(t_flags *b, char **str)
{
	*str = ft_strchar(' ', b->size_lenght - 1);
	if (b->fill_w_zero == 1)
		*str = ft_strchar('0', b->size_lenght - 1);
	b->size_lenght--;
	ft_putstr(*str);
}

int			ft_apply_width(t_flags b, char c)
{
	char	*str;
	int		len;

	str = ft_strchar(c, 1);
	str = ft_check_if_flags_str(b, str);
	if (b.size_prec == 0)
		str[ft_strlen(str) - 1] = c;
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int			ft_check_strong_bite(char byte)
{
	if ((byte & 128) == 0)
		return (1);
	if ((byte & 224) == 192)
		return (2);
	if ((byte & 240) == 224)
		return (3);
	if ((byte & 248) == 240)
		return (4);
	return (0);
}

char		*ftf_join_flags(char *str, t_flags b, char *tmp)
{
	if (str[0] == '-' && b.fill_w_zero == 1)
		str = ft_strjoin("-", ft_strjoin(tmp, &str[1]));
	else if ((str[0] == '+' || b.pos_nul == 1) && b.fill_w_zero == 1)
		str = ft_strjoin("+", ft_strjoin(tmp, &str[1]));
	else if ((str[0] == ' ' || b.pos_nul == 1) && b.fill_w_zero == 1)
		str = ft_strjoin(" ", ft_strjoin(tmp, &str[1]));
	else if (str[0] == '0' && str[1] == 'x' && b.fill_w_zero == 1)
		str = ft_strjoin("0x", ft_strjoin(tmp, &str[2]));
	else if (str[0] == '0' && str[1] == 'X' && b.fill_w_zero == 1)
		str = ft_strjoin("0X", ft_strjoin(tmp, &str[2]));
	else
		str = ft_strjoin(tmp, str);
	return (str);
}
