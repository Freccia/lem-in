/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:14:38 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/14 09:59:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;

	if (s1)
		ls1 = ft_strlen(s1);
	if (s2)
		ls2 = ft_strlen(s2);
	if (!s1 && s2)
	{
		str = ft_strnew(ls2 + 1);
		return (str ? ft_strcpy(str, s2) : NULL);
	}
	if (!s2 && s1)
	{
		str = ft_strnew(ls1 + 1);
		return (str ? ft_strcpy(str, s1) : NULL);
	}
	if (s1 && s2)
	{
		str = ft_strnew(ls1 + ls2 + 1);
		return (str ? ft_strcat(ft_strcpy(str, s1), s2) : NULL);
	}
	return (NULL);
}
