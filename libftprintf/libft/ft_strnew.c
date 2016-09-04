/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:57:06 by lfabbro           #+#    #+#             */
/*   Updated: 2015/12/03 16:42:07 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*space;
	int		i;

	i = 0;
	if ((space = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while ((size_t)i < size)
	{
		space[i] = '\0';
		i++;
	}
	space[i] = '\0';
	return (space);
}
