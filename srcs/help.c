/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 12:18:36 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 15:57:10 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_line			*new_line(char *line)
{
	t_line		*file;

	if ((file = (t_line*)malloc(sizeof(t_line))) == NULL)
		malloc_error();
	file->line = ft_strdup(line);
	file->next = NULL;
	return (file);
}

t_node			*mdfind_node(t_data *data, char *node)
{
	t_node		*ptr;

	ptr = data->nodes;
	while (ptr)
	{
		if (!ft_strcmp(ptr->name, node))
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int				ft_whichtype(char *line)
{
	int			i;

	i = 0;
	if (line[i] == '#')
	{
		if (!ft_strcmp(line, "##start"))
			return (START);
		if (!ft_strcmp(line, "##end"))
			return (END);
	}
	return (NODE);
}

int				ft_strnchr(char *str, char c)
{
	int			i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			++i;
		++str;
	}
	return (i);
}

int				ft_isalldigits(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		++i;
	}
	return (i);
}
