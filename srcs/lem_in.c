/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 13:40:30 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/05 16:22:13 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_ant			*set_ants_paths(t_paths *paths, int n_ants)
{
	t_ant			*ants;
	t_ant			*ant_ptr;
	t_paths			*path_ptr;
	int				i;

	i = 1;
	ants = new_ant(i, paths->path->next);
	ant_ptr = ants;
	path_ptr = paths->next;
	if (path_ptr == NULL)
		path_ptr = paths;
	while (++i <= n_ants)
	{
		ant_ptr->next = new_ant(i, path_ptr->path->next);
		ant_ptr = ant_ptr->next;
		path_ptr = path_ptr->next;
		if (path_ptr == NULL)
			path_ptr = paths;
	}
	return (ants);
}

static t_ant			*advance_ant(t_ant *ant)
{
	if (ant->path)
	{
		ft_printf("L%d-%s ", ant->n, ant->path->node->name);
		ant->path = ant->path->next;
	}
	return (ant->next);
}

static int				go_ants(t_ant *ants, t_paths *paths)
{
	t_ant			*ant;
	t_paths			*paths_ptr;
	int				n_shots;
	int				complete;

	complete = 1;
	n_shots = 0;
	while (complete)
	{
		ant = ants;
		paths_ptr = paths;
		while (ant && ant->go)
			ant = advance_ant(ant);
		while (paths_ptr && ant)
		{
			ant->go = 1;
			ant = advance_ant(ant);
			paths_ptr = paths_ptr->next;
		}
		++n_shots;
		complete = check_complete(ants);
		ft_putchar('\n');
	}
	return (n_shots);
}

void					lem_in(t_data *data)
{
	t_ant			*ants;
	t_paths			*paths;
	int				n_shots;

	n_shots = 0;
	paths = NULL;
	ants = NULL;
	set_nodes_weights(data);
	option_weights(data);
	while (add_path(data, &paths))
		;
	if (paths == NULL)
		ft_error();
	ants = set_ants_paths(paths, data->n_ants);
	option_paths(data, paths);
	n_shots = go_ants(ants, paths);
	option_nshots(data, n_shots);
	ft_free_paths(paths);
	ft_free_ants(ants);
}
