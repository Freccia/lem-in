/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:05:33 by lfabbro           #+#    #+#             */
/*   Updated: 2015/12/14 18:12:55 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nb_len(unsigned int n)
{
	int		len;

	len = 0;
	if ((int)n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_nbc(char *nbc, unsigned int nb, int nb_len, int sign)
{
	nbc += (nb_len);
	*nbc = '\0';
	while (nb != 0)
	{
		*--nbc = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (sign)
		*--nbc = '-';
	return (nbc);
}

char		*ft_itoa(int n)
{
	char			*nbc;
	int				sign;
	int				nb_len;
	unsigned int	nb;

	if (n == 0)
	{
		if ((nbc = (char *)malloc(sizeof(char) * 2)) == NULL)
			return (0);
		*nbc = '0';
		*++nbc = '\0';
		return (--nbc);
	}
	nb = n;
	sign = 0;
	nb_len = ft_nb_len(nb);
	if (n < 0)
	{
		sign = 1;
		nb = -n;
	}
	if ((nbc = (char *)malloc(sizeof(*nbc) * nb_len + 1)) == NULL)
		return (NULL);
	nbc = ft_nbc(nbc, nb, nb_len, sign);
	return (nbc);
}
