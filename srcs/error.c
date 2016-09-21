/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 11:09:31 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/05 16:00:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

void			malloc_error(void)
{
	ft_printf("Malloc failed. Stop.\n");
	exit(0);
}

void			ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
