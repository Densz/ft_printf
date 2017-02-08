/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:04:04 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 13:58:44 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					size_of_binary(unsigned int b)
{
	char			*str_binary;
	int				len;
	int				i;
	char			*tmp;

	i = 31;
	str_binary = (char *)malloc(sizeof(char) * (32 + 1));
	str_binary[32] = '\0';
	while (i >= 0)
	{
		str_binary[i] = b % 2 + '0';
		b = b / 2;
		i--;
	}
	tmp = str_binary;
	str_binary = ft_strchr(tmp, '1');
	len = ft_strlen(str_binary);
	free(tmp);
	return (len);
}

char				*ft_print_two_octet(unsigned int i, char *str)
{
	unsigned int	octet1;
	unsigned int	octet2;

	octet1 = ((i << 26) >> 26) + 128;
	octet2 = (((i >> 6) << 27) >> 27) + 192;
	str[0] = octet2;
	str[1] = octet1;
	return (str);
}

char				*ft_print_three_octet(unsigned int i, char *str)
{
	unsigned int	octet1;
	unsigned int	octet2;
	unsigned int	octet3;

	octet1 = ((i << 26) >> 26) + 128;
	octet2 = (((i >> 6) << 26) >> 26) + 128;
	octet3 = (((i >> 12) << 28) >> 28) + 224;
	str[0] = octet3;
	str[1] = octet2;
	str[2] = octet1;
	return (str);
}

char				*ft_print_four_octet(unsigned int i, char *str)
{
	unsigned int	octet1;
	unsigned int	octet2;
	unsigned int	octet3;
	unsigned int	octet4;

	octet1 = ((i << 26) >> 26) + 128;
	octet2 = (((i >> 6) << 26) >> 26) + 128;
	octet3 = (((i >> 12) << 28) >> 28) + 128;
	octet4 = (((i >> 18) << 29) >> 29) + 240;
	str[0] = octet4;
	str[1] = octet3;
	str[2] = octet2;
	str[3] = octet1;
	return (str);
}

char				*ft_unicode(wchar_t c)
{
	unsigned int	i;
	int				size;
	char			*str;

	i = (unsigned int)c;
	str = NULL;
	str = ft_strnew(4 + 1);
	size = size_of_binary(i);
	if (size <= 7)
	{
		str = ft_strnew(1);
		str[0] = i;
	}
	else if (size <= 11)
		str = ft_print_two_octet(i, str);
	else if (size <= 16)
		str = ft_print_three_octet(i, str);
	else if (size > 16 && size <= 21)
		str = ft_print_four_octet(i, str);
	str[4] = '\0';
	return (str);
}
