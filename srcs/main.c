/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 11:04:19 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 16:11:05 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				main(int argc, char **argv)
{
	t_data		*data;
	int			opt;

	opt = 0;
	if (argc > 1)
		opt = parsing_options(argc, argv);
	if ((data = parsing(0, opt)) == NULL)
		ft_error();
	check_data(data);
	lem_in(data);
	ft_free_data(data);
	return (0);
}
