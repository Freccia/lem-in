/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:54:04 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/29 18:06:21 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wchar_size(wchar_t wchar)
{
	int			len;

	len = 0;
	if (wchar <= 0xFF)
		len = 1;
	else if (wchar <= 0xFFF)
		len = 2;
	else if (wchar <= 0xFFFF)
		len = 3;
	else if (wchar <= 0x10FFFF)
		len = 4;
	return (len);
}
