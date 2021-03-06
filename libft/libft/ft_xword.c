/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xword.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 13:22:06 by lfabbro           #+#    #+#             */
/*   Updated: 2016/12/10 12:15:05 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(int x, char *str, char div)
{
	int			n;
	int			i;

	n = 1;
	i = -1;
	while (str[++i] && n < x)
		if (str[i] == div)
			++n;
	if (n != x)
		return (-1);
	return (i);
}

char			*ft_xword(char *str, int x, char div)
{
	int			i;
	int			j;
	char		*word;

	i = -1;
	word = NULL;
	if ((i = ft_count_words(x, str, div)) < 0)
		return (NULL);
	j = i;
	while (str[j] && str[j] != div)
		++j;
	word = ft_strndup(&str[i], (j - i));
	return (word);
}

