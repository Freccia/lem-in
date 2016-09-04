/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 10:57:23 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 15:55:50 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			ft_free_file(t_line *file)
{
	t_line			*ptr;
	t_line			*tmp;

	ptr = file;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp->line);
		tmp->line = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void				ft_free_tubes(t_tube *tubes)
{
	t_tube			*ptr;
	t_tube			*tmp;

	ptr = tubes;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		tmp->node = NULL;
		tmp->next = NULL;
		free(tmp);
	}
	tubes = NULL;
}

void				ft_free_paths(t_paths *paths)
{
	t_paths			*ptr;

	while (paths)
	{
		ptr = paths;
		paths = paths->next;
		ft_free_tubes(ptr->path);
		free(ptr);
	}
}

void				ft_free_ants(t_ant *ants)
{
	t_ant			*ptr;

	while (ants)
	{
		ptr = ants;
		ants = ants->next;
		ptr->path = NULL;
		ptr->next = NULL;
		free(ptr);
	}
}

void				ft_free_data(t_data *data)
{
	t_node			*node_ptr;
	t_node			*node_tmp;

	node_ptr = data->nodes;
	while (node_ptr)
	{
		ft_free_tubes(node_ptr->tubes);
		node_tmp = node_ptr;
		node_ptr = node_ptr->next;
		free(node_tmp->name);
		node_tmp->name = NULL;
		free(node_tmp);
	}
	ft_free_file(data->file);
	data->file = NULL;
	data->start = NULL;
	data->end = NULL;
	free(data);
	data = NULL;
}
