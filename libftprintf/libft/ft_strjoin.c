/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:14:38 by lfabbro           #+#    #+#             */
/*   Updated: 2015/12/09 18:07:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	int		len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((cpy = (char *)malloc(sizeof(*s1) * len)) == NULL)
			return (NULL);
		ft_strcpy(cpy, s1);
		ft_strcat(cpy, s2);
		return (cpy);
	}
	return (0);
}
