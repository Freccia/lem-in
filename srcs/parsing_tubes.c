/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tubes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 10:22:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/06 11:27:18 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			add_tube(t_node *src, t_node *dst)
{
	t_tube			*ptr;
	t_tube			*ptr2;

	if (src && dst)
	{
		ptr = NULL;
		ptr2 = src->tubes;
		if (!ft_strcmp(src->name, dst->name))
			return (1);
		while (ptr2)
		{
			if (!ft_strcmp(ptr2->node->name, dst->name))
				return (0);
			ptr2 = ptr2->next;
		}
		ptr = new_tube(dst);
		ptr->next = src->tubes;
		src->tubes = ptr;
		return (0);
	}
	return (1);
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
	return (NULL);
}

static t_line		*first_line(char *line, t_data *data, t_line *file_ptr, \
		int *valid)
{
	t_node			*ptr1;
	t_node			*ptr2;

	ptr1 = NULL;
	ptr2 = NULL;
	*valid = 1;
	if (line[0] != '#')
	{
		if (ft_strnchr(line, '-') != 1)
		{
			*valid = 0;
			return (file_ptr);
		}
		ptr1 = find_node(line, data->nodes, 1);
		ptr2 = find_node(line, data->nodes, 2);
		if (add_tube(ptr1, ptr2) && !(*valid = 0))
			return (file_ptr);
		if (add_tube(ptr2, ptr1) && !(*valid = 0))
			return (file_ptr);
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
	int				valid;

	ptr1 = NULL;
	ptr2 = NULL;
	file_ptr = first_line(line, data, file_ptr, &valid);
	while (get_next_line(fd, &line) && valid)
	{
		if (line[0] != '#')
		{
			if (ft_strnchr(line, '-') != 1)
				break ;
			ptr1 = find_node(line, data->nodes, 1);
			ptr2 = find_node(line, data->nodes, 2);
			if (add_tube(ptr1, ptr2))
				break ;
			if (add_tube(ptr2, ptr1))
				break ;
		}
		file_ptr->next = new_line(line);
		file_ptr = file_ptr->next;
		free(line);
	}
	free(line);
}
