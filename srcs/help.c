/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 12:18:36 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/06 11:42:15 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				skip_comments_and_get_line(int fd, char **line)
{
	int			ret;

	while ((ret = get_next_line(fd, line)) && *line[0] == '#')
		;
	if (ret < 0)
		return (-1);
	return (0);
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

int				ft_whichtype(char *line, int type)
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
	return (type);
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
		if (!ft_isdigit(line[i]) && line[i] != '-')
			return (0);
		++i;
	}
	return (i);
}
