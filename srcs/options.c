/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 14:34:03 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 17:02:50 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			option_weights(t_data *data)
{
	(!(data->opt & 32)) ? print_file(data->file) : NULL;
	(data->opt & 4) ? print_weights(data->nodes) : NULL;
	(data->opt & 16) ? ft_printf("Number of ants: %d\n\n", data->n_ants) : 0;
}

void			option_paths(t_data *data, t_paths *paths)
{
	(data->opt & 2) ? print_paths(paths) : NULL;
}

void			option_nshots(t_data *data, int n_shots)
{
	(data->opt & 8) ? (ft_printf("Number of shots: %d\n", n_shots)) : 0;
}

static void		print_help(void)
{
	ft_printf("Usage: lem-in [-p] [-w] < file\n");
	ft_printf("    -a: prints number of ants\n");
	ft_printf("    -i: hide map\n");
	ft_printf("    -n: prints number of shots\n");
	ft_printf("    -p: prints found paths\n");
	ft_printf("    -w: prints nodes weights\n");
	ft_printf("    -h: prints this help menu\n\n");
}

int				parsing_options(int argc, char **argv)
{
	int			opt;
	int			i;

	opt = 0;
	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-p"))
			opt = opt | 2;
		else if (ft_strequ(argv[i], "-w"))
			opt = opt | 4;
		else if (ft_strequ(argv[i], "-n"))
			opt = opt | 8;
		else if (ft_strequ(argv[i], "-a"))
			opt = opt | 16;
		else if (ft_strequ(argv[i], "-i"))
			opt = opt | 32;
		else if (ft_strequ(argv[i], "-h"))
			print_help();
	}
	return (opt);
}
