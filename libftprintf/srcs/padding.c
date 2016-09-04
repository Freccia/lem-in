/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:50:45 by lfabbro           #+#    #+#             */
/*   Updated: 2016/03/29 19:02:22 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		padding_left(t_struct *st, int limit)
{
	if (!(st->flags.pad & PAD_RIGHT))
		while (st->flags.width >= 0 && st->flags.width-- > limit)
			st->pc += ft_putchar(st->flags.padchar);
}

void		padding_right(t_struct *st, int limit)
{
	if (st->flags.pad & PAD_RIGHT)
		while (st->flags.width >= 0 && st->flags.width-- > limit)
			st->pc += ft_putchar(st->flags.padchar);
}
