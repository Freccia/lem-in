/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:20:35 by lfabbro           #+#    #+#             */
/*   Updated: 2015/12/09 18:02:18 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		new_str = malloc(sizeof(*s) * len + 1);
		if (new_str == NULL)
			return (0);
		while (i < len && s[i])
		{
			new_str[i] = f(i, s[i]);
			i++;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	return (0);
}
