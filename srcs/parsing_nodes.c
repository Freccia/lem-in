/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 10:22:42 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 16:31:35 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <limits.h>

static int				new_node_info(t_node *node, char *line, int type)
{
	if (line && line[0] != 'L')
	{
		node->name = ft_xword(line, 1, ' ');
		node->type = type;
		return (0);
	}
	return (-1);
}

static t_node			*add_node_to_data(t_data *data)
{
	t_node			*ptr;

	ptr = new_node();
	if (data->nodes != NULL)
		ptr->next = data->nodes;
	return (ptr);
}

static int				get_node(char *line, t_data *data, int type)
{
	data->nodes = add_node_to_data(data);
	if (type == START)
		data->start = data->nodes;
	else if (type == END)
		data->end = data->nodes;
	return (new_node_info(data->nodes, line, type));
}

static t_line			*parse_nodes(char **line, t_data *data, int fd)
{
	int				type;
	int				max_nodes;
	t_line			*file_ptr;

	type = 0;
	max_nodes = 0;
	file_ptr = data->file;
	while (get_next_line(fd, line) && ++max_nodes < INT_MAX)
	{
		if (ft_strchr(*line, '-') && *line[0] != '#')
			break ;
		if (*line[0] != '#')
		{
			(get_node(*line, data, type) < 0) ? ft_error() : NULL;
			data->n_nodes += 1;
			type = 0;
		}
		else
			type = ft_whichtype(*line);
		file_ptr->next = new_line(*line);
		file_ptr = file_ptr->next;
		free(*line);
	}
	(max_nodes <= 0 || max_nodes > INT_MAX) ? ft_error() : NULL;
	return (file_ptr);
}

t_data					*parsing(int fd, int opt)
{
	t_data			*data;
	t_line			*file_ptr;
	char			*line;

	data = new_data();
	data->opt = opt;
	file_ptr = NULL;
	line = NULL;
	if (get_next_line(fd, &line) < 0)
		ft_error();
	if (!ft_isalldigits(line))
		ft_error();
	if ((data->n_ants = ft_atoi(line)) <= 0 || data->n_ants > INT_MAX)
		ft_error();
	data->file = new_line(line);
	free(line);
	file_ptr = parse_nodes(&line, data, fd);
	parse_tubes(line, data, fd, file_ptr);
	return (data);
}
