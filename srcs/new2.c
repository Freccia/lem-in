/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 11:23:52 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/06 11:24:18 by lfabbro          ###   ########.fr       */
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
