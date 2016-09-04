/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tubes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 10:22:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 16:28:25 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			add_tube(t_node *src, t_node *dst)
{
	t_tube			*ptr;
	t_tube			*ptr2;

	ptr = NULL;
	ptr2 = src->tubes;
	while (ptr2)
	{
		if (!ft_strcmp(ptr2->node->name, dst->name))
			return ;
		ptr2 = ptr2->next;
	}
	ptr = new_tube(dst);
	ptr->next = src->tubes;
	src->tubes = ptr;
}

static t_node		*find_node(char *line, t_node *nodes, int n)
{
	char			*array;
	t_node			*ptr;

	ptr = nodes;
	array = ft_xword(line, n, '-');
	while (ptr)
	{
		if (!ft_strcmp(ptr->name, array))
		{
			free(array);
			return (ptr);
		}
		ptr = ptr->next;
	}
	ft_error();
	return (NULL);
}

static t_line		*first_line(char *line, t_data *data, t_line *file_ptr)
{
	t_node			*ptr1;
	t_node			*ptr2;

	ptr1 = NULL;
	ptr2 = NULL;
	if (line[0] != '#')
	{
		if (ft_strnchr(line, '-') != 1)
			ft_error();
		ptr1 = find_node(line, data->nodes, 1);
		ptr2 = find_node(line, data->nodes, 2);
		add_tube(ptr1, ptr2);
		add_tube(ptr2, ptr1);
	}
	file_ptr->next = new_line(line);
	file_ptr = file_ptr->next;
	free(line);
	return (file_ptr);
}

void				parse_tubes(char *line, t_data *data, int fd, \
		t_line *file_ptr)
{
	t_node			*ptr1;
	t_node			*ptr2;

	ptr1 = NULL;
	ptr2 = NULL;
	file_ptr = first_line(line, data, file_ptr);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#')
		{
			if (ft_strnchr(line, '-') != 1)
				ft_error();
			ptr1 = find_node(line, data->nodes, 1);
			ptr2 = find_node(line, data->nodes, 2);
			add_tube(ptr1, ptr2);
			add_tube(ptr2, ptr1);
		}
		file_ptr->next = new_line(line);
		file_ptr = file_ptr->next;
		free(line);
	}
	free(line);
}
