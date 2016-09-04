/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 12:43:42 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 16:27:52 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			print_file(t_line *file)
{
	t_line		*ptr;

	ptr = file;
	while (ptr)
	{
		ft_printf("%s\n", ptr->line);
		ptr = ptr->next;
	}
	ft_putchar('\n');
}

void			print_weights(t_node *nodes)
{
	t_node		*ptr;

	ptr = nodes;
	while (ptr)
	{
		ft_printf("node: %s        weight: %d\n", ptr->name, ptr->weight);
		ptr = ptr->next;
	}
	ft_putchar('\n');
}

void			print_paths(t_paths *t)
{
	t_paths		*t_ptr;
	t_tube		*s;
	int			i;

	i = 1;
	t_ptr = t;
	while (t_ptr)
	{
		s = t_ptr->path;
		ft_printf("path #%d:", i);
		while (s)
		{
			ft_printf(" %s", s->node->name);
			s = s->next;
		}
		ft_putchar('\n');
		t_ptr = t_ptr->next;
		++i;
	}
	ft_putchar('\n');
}
