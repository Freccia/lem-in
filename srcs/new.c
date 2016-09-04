/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 11:11:51 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 13:39:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <limits.h>

t_ant				*new_ant(int n, t_tube *path)
{
	t_ant		*ant;

	if ((ant = (t_ant*)malloc(sizeof(t_ant))) == NULL)
		malloc_error();
	ant->n = n;
	ant->go = 0;
	ant->path = path;
	ant->next = NULL;
	return (ant);
}

t_paths				*new_paths(void)
{
	t_paths		*paths;

	if ((paths = (t_paths*)malloc(sizeof(t_paths))) == NULL)
		malloc_error();
	paths->path = NULL;
	paths->next = NULL;
	return (paths);
}

t_tube				*new_tube(t_node *dst)
{
	t_tube		*tube;

	if ((tube = (t_tube*)malloc(sizeof(t_tube))) == NULL)
		malloc_error();
	tube->node = dst;
	tube->next = NULL;
	return (tube);
}

t_node				*new_node(void)
{
	t_node		*node;

	if ((node = (t_node*)malloc(sizeof(t_node))) == NULL)
		malloc_error();
	node->name = NULL;
	node->type = 0;
	node->weight = 0;
	node->next = NULL;
	node->tubes = NULL;
	return (node);
}

t_data				*new_data(void)
{
	t_data		*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		malloc_error();
	data->n_ants = 0;
	data->n_nodes = 0;
	data->max_weight = 0;
	data->i = 0;
	data->opt = 0;
	data->start = NULL;
	data->end = NULL;
	data->nodes = NULL;
	return (data);
}
