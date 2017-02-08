/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:20:09 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 15:52:00 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j])
		j++;
	if (i == j)
		return (ft_strnew(0));
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
