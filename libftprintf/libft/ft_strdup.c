/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:09:05 by lfabbro           #+#    #+#             */
/*   Updated: 2015/12/09 18:43:49 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	int		lenght;
	int		i;
	char	*dup;

	lenght = ft_strlen(s1);
	i = 0;
	dup = (char*)malloc(sizeof(*dup) * lenght + 1);
	if (dup == NULL)
		return (0);
	while (i < lenght)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
