/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:00:18 by lfabbro           #+#    #+#             */
/*   Updated: 2016/01/15 18:56:31 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_justforpleasure(char const *s, int cpy_len, char *cpy, int fwd)
{
	int		i;

	i = 0;
	while (i < cpy_len)
	{
		cpy[i] = s[fwd];
		i++;
		fwd++;
	}
	cpy[cpy_len] = '\0';
	return (cpy);
}

static int	ft_set_cpy_len(int fwd, int bkw, int len)
{
	int		cpy_len;

	if (bkw)
		cpy_len = (len - fwd - (len - bkw));
	else
		cpy_len = 0;
	return (cpy_len);
}

char		*ft_strtrim(char const *s)
{
	char	*cpy;
	int		len;
	int		cpy_len;
	int		bkw;
	int		fwd;

	if (s)
	{
		len = ft_strlen(s);
		bkw = len;
		fwd = 0;
		while (s[fwd] == ' ' || s[fwd] == '\n' || s[fwd] == '\t')
			fwd++;
		while (bkw && (s[bkw - 1] == ' ' || s[bkw - 1] == '\n' || \
					s[bkw - 1] == '\t'))
			bkw--;
		cpy_len = ft_set_cpy_len(fwd, bkw, len);
		if ((cpy = (char *)malloc(sizeof(char) * cpy_len + 1)) == NULL)
			return (0);
		cpy = ft_justforpleasure(s, cpy_len, cpy, fwd);
		return (cpy);
	}
	return (0);
}
