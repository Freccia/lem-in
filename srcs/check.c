/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 13:36:58 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 15:56:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					check_complete(t_ant *ants)
{
	t_ant			*ptr;

	ptr = ants;
	while (ptr)
	{
		if (ptr->path)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static int			check_double_nodes(t_data *data)
{
	t_node			*ptr;
	t_node			*ptr2;

	ptr = data->nodes;
	while (ptr)
	{
		ptr2 = ptr->next;
		while (ptr2)
		{
			if (!ft_strcmp(ptr->name, ptr2->name))
				return (-1);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	return (0);
}

int					check_data(t_data *data)
{
	if (data->start == NULL || data->end == NULL)
		ft_error();
	else if (data->start->tubes == NULL || data->end->tubes == NULL)
		ft_error();
	else if (check_double_nodes(data) < 0)
		ft_error();
	return (0);
}
