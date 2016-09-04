/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 10:59:13 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/04 16:10:56 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define NODE			0
# define START			2
# define END			1

# include "libftprintf.h"

typedef struct s_tube			t_tube;
typedef struct s_node			t_node;
typedef struct s_paths			t_paths;
typedef struct s_ant			t_ant;

struct							s_ant
{
	int							n;
	int							go;
	t_tube						*path;
	t_ant						*next;
};

struct							s_paths
{
	t_tube						*path;
	t_paths						*next;
};

struct							s_tube
{
	t_node						*node;
	t_tube						*next;
};

struct							s_node
{
	char						*name;
	int							type;
	int							weight;
	t_tube						*tubes;
	t_node						*next;
};

typedef struct					s_line
{
	char						*line;
	struct s_line				*next;
}								t_line;

typedef struct					s_data
{
	t_line						*file;
	int							n_ants;
	int							n_nodes;
	int							max_weight;
	int							i;
	int							opt;
	t_node						*start;
	t_node						*end;
	t_node						*nodes;
}								t_data;

/*
**	LEM_IN
*/
void							lem_in(t_data *data);

/*
**	WEIGHTS
*/
int								set_nodes_weights(t_data *data);

/*
**	PATH
*/
t_paths							*add_path(t_data *data, t_paths **paths);

/*
**	PARSING
*/
t_data							*parsing(int fd, int opt);
void							parse_tubes(char *line, t_data *data, int fd, \
		t_line *file_ptr);

/*
**	OPTIONS
*/
int								parsing_options(int argc, char **argv);
void							option_weights(t_data *data);
void							option_paths(t_data *data, t_paths *paths);
void							option_nshots(t_data *data, int n_shots);

/*
**	CHECK
*/
int								check_complete(t_ant *ants);
int								check_data(t_data *data);

/*
**	NEW
*/
t_ant							*new_ant(int n, t_tube *path);
t_paths							*new_paths(void);
t_node							*new_node(void);
t_data							*new_data(void);
t_tube							*new_tube(t_node *dst);

/*
**	HELP
*/
t_line							*new_line(char *line);
int								ft_whichtype(char *line);
int								ft_strnchr(char *str, char c);
int								ft_isalldigits(char *line);
t_node							*mdfind_node(t_data *data, char *node);
char							*ft_xword(char *str, int x, char div);

/*
**	FREE
*/
void							ft_free_tubes(t_tube *tubes);
void							ft_free_ants(t_ant *ants);
void							ft_free_paths(t_paths *paths);
void							ft_free_data(t_data *data);

/*
**	PRINT
*/
void							print_file(t_line *file);
void							print_tubes(t_node *n);
void							print_weights(t_node *nodes);
void							print_all_tubes(t_node *nodes);
void							print_paths(t_paths *t);

/*
**	ERROR
*/
void							malloc_error(void);
void							ft_error(void);

#endif
