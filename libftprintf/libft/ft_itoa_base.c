/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:40:39 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/15 18:46:50 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		get_size(long val, long base)
{
	int		size;

	size = 0;
	if (val < 0)
	{
		val *= -1;
		if (base == 10)
			++size;
	}
	while (val)
	{
		val /= base;
		++size;
	}
	return (size);
}

static char		*ft_return_zero(void)
{
	char	*num;

	num = NULL;
	if ((num = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

static char		*itoa_base_return(long value, long base, char set)
{
	int			size;
	char		*num;

	size = get_size(value, base);
	if ((num = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	num[size] = '\0';
	if (value < 0)
	{
		if (base == 10)
			num[0] = '-';
		value *= -1;
	}
	while (value)
	{
		if (value % base < 10)
			num[--size] = "0123456789"[value % base];
		else
			num[--size] = set + ((value % base) - 10);
		value /= base;
	}
	return (num);
}

char			*ft_itoa_base(int value, int base, char set)
{
	long	value_;
	long	base_;

	value_ = value;
	base_ = base;
	if (base_ < 2 || base_ > 16)
		return (NULL);
	if (value_ == 0)
		return (ft_return_zero());
	return (itoa_base_return(value_, base_, set));
}
