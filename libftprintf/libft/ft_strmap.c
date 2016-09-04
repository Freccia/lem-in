/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:33:20 by lfabbro           #+#    #+#             */
/*   Updated: 2015/12/09 18:00:34 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*new_str;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		new_str = malloc(sizeof(*s) * len + 1);
		if (!new_str)
			return (0);
		while (i < len)
		{
			if (s[i])
				new_str[i] = f(s[i]);
			i++;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	return (0);
}
