/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:01:35 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/17 11:04:48 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchar(char c, size_t size)
{
	char		*str;

	str = (char*)malloc(size + 1);
	ft_memset(str, c, size);
	str[size] = '\0';
	return (str);
}
