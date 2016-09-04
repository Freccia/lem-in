/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weights.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 15:32:48 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 13:56:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			set_end_weight(t_data *data)
{
	data->end->weight = 1;
	data->max_weight = 1;
	data->i = 1;
}

static void			set_impasse(t_data *data)
{
	t_node			*ptr;

	ptr = data->nodes;
	while (ptr)
	{
		if (ptr->weight == 0)
			++data->i;
		if (ptr->weight == -1 || ptr->weight == 0)
			ptr->weight = data->max_weight + 1;
		ptr = ptr->next;
	}
}

static int			set_weight(t_data *data, t_node *ptr)
{
	t_tube			*tube_ptr;

	tube_ptr = ptr->tubes;
	while (tube_ptr && tube_ptr->node->weight != data->max_weight)
		tube_ptr = tube_ptr->next;
	if (!tube_ptr)
		return (1);
	ptr->weight = data->max_weight + 1;
	++data->i;
	return (0);
}

int					set_nodes_weights(t_data *data)
{
	t_node			*ptr;

	set_end_weight(data);
	while (data->i < data->n_nodes && data->max_weight < (2 * data->n_nodes))
	{
		ptr = data->nodes;
		while (ptr)
		{
			if (ptr->tubes == NULL && !ptr->weight)
			{
				ptr->weight = -1;
				++data->i;
			}
			else if (!ptr->weight)
				set_weight(data, ptr);
			if (!ft_strcmp(data->start->name, ptr->name) && ptr->weight > 0)
				set_impasse(data);
			ptr = ptr->next;
		}
		++data->max_weight;
	}
	return (0);
}
