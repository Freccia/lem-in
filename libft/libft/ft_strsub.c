/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:01:10 by lfabbro           #+#    #+#             */
/*   Updated: 2015/12/09 18:05:31 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tron;
	size_t		i;

	i = 0;
	if (s)
	{
		if ((tron = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (i < len)
		{
			tron[i] = s[start + i];
			i++;
		}
		tron[i] = '\0';
		return (tron);
	}
	return (0);
}
