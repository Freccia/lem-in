/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 10:22:42 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/20 10:24:49 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <limits.h>

static int				new_node_info(t_node *node, char *line, int type)
{
	char			*coord;

	coord = NULL;
	if (line && line[0] != 'L')
	{
		node->name = ft_xword(line, 1, ' ');
		(ft_strchr(node->name, '-') > 0 ? ft_error() : NULL);
		(ft_strchr(node->name, '\t') > 0 ? ft_error() : NULL);
		coord = ft_xword(line, 2, ' ');
		(!ft_isalldigits(coord)) ? ft_error() : NULL;
		coord = ft_xword(line, 3, ' ');
		(!ft_isalldigits(coord)) ? ft_error() : NULL;
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

	type = NODE;
	max_nodes = 0;
	file_ptr = data->file;
	while (get_next_line(fd, line) && ++max_nodes < INT_MAX)
	{
		if (ft_strnchr(*line, ' ') != 2 && *line[0] != '#')
			break ;
		if (*line[0] != '#')
		{
			(get_node(*line, data, type) < 0) ? ft_error() : NULL;
			data->n_nodes += 1;
			type = NODE;
		}
		else
			type = ft_whichtype(*line, type);
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
	skip_comments_and_get_line(fd, &line);
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
