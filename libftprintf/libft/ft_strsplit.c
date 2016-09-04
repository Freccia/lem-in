/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:47:04 by lfabbro           #+#    #+#             */
/*   Updated: 2016/01/18 13:54:46 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_of_w(char const *s, char c)
{
	size_t	nw;

	nw = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			nw++;
			while (*s != c && *s)
				s++;
		}
	}
	return (nw);
}

static size_t	ft_strlen_c(char const *s, char c)
{
	size_t		len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static char		*cp_word(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if ((str = (char *)malloc(sizeof(*s) * ft_strlen_c(s, c) + 1)) == NULL)
		return (NULL);
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**justforpleasure(char const *s, char c, int j)
{
	char	**tab;
	size_t	nw;

	tab = NULL;
	nw = ft_num_of_w(s, c);
	j = 0;
	if ((tab = (char **)malloc(sizeof(char*) * nw + 1)) == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			tab[j] = NULL;
			tab[j] = cp_word(s, c);
			s += ft_strlen_c(s, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;

	tab = justforpleasure(s, c, 0);
	if (s)
		return (tab);
	return (0);
}
