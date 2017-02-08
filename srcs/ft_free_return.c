/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:25:05 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/18 14:26:50 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_free_return(char **str)
{
	int len;

	len = 0;
	if (str == NULL)
		return (0);
	ft_putstr(*str);
	len = ft_strlen(*str);
	free(*str);
	*str = NULL;
	return (len);
}

int			ft_free_flags_return(char **str, t_flags b)
{
	int len;

	len = 0;
	if (str == NULL)
		return (0);
	*str = ft_check_if_flags_int(b, *str);
	ft_putstr(*str);
	len = ft_strlen(*str);
	free(*str);
	*str = NULL;
	return (len);
}
