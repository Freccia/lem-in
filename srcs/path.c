/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 14:04:29 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 16:32:43 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_node			*min_weight_node(t_tube *tube, char *start)
{
	t_tube			*ptr;
	t_node			*min;
	t_node			*to_free;

	ptr = tube;
	min = (tube->node->weight >= 0 && ft_strcmp(tube->node->name, start)) ? \
			(tube->node) : (new_node());
	min->weight = (min->name == NULL) ? INT_MAX : min->weight;
	to_free = (min->name == NULL) ? min : NULL;
	while (ptr)
	{
		if (ft_strcmp(ptr->node->name, start))
			if (ptr->node->weight >= 0 && ptr->node->weight < min->weight)
				min = ptr->node;
		ptr = ptr->next;
	}
	if (min->name == NULL)
	{
		free(to_free);
		return (NULL);
	}
	(to_free != NULL) ? free(to_free) : NULL;
	if (min->weight != END)
		min->weight = -1;
	return (min);
}

static t_tube			*find_path(t_data *data)
{
	t_tube			*path;
	t_tube			*path_ptr;
	t_node			*pos;
	int				limit;

	path = new_tube(data->start);
	path_ptr = path;
	pos = data->start;
	limit = 0;
	while (ft_strcmp(pos->name, data->end->name) && \
			limit <= data->max_weight + data->n_ants)
	{
		if ((pos = min_weight_node(pos->tubes, data->start->name)) == NULL)
		{
			ft_free_tubes(path);
			return (NULL);
		}
		path_ptr->next = new_tube(pos);
		path_ptr = path_ptr->next;
		++limit;
	}
	(ft_strcmp(pos->name, data->end->name)) ? ft_free_tubes(path) : NULL;
	return (path);
}

t_paths					*add_path(t_data *data, t_paths **paths)
{
	t_paths			*t;
	t_paths			*ptr;

	t = new_paths();
	if ((t->path = find_path(data)) == NULL)
	{
		free(t);
		return (NULL);
	}
	ptr = *paths;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = t;
	}
	else
		*paths = t;
	return (*paths);
}
