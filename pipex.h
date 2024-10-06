/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:57:51 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/06 18:28:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	**av;
	char	**env;
	int		ac;
	char	**path;
	int		cmd_count;
	pid_t	*pid;
	int		error;
	int		fd[2];
	int		infile;
	int outfile;
}			t_data;

// pathing

char		**find_path(t_data *data);
char		*get_path_var(t_data *data);
char		*add_slash(char *path);
char		**add_slash_to_paths(char **paths);

// parsing + check

void		init_data(t_data *data, int ac, char **av, char **env);
void		opening_file(t_data *data);
char		*have_access(t_data *data, char *cmd);
int			looking_using(t_data *data, char **cmd, int i);
char		**parsing_cmd(t_data data, int i);
void		path_not_found(char **cmd);

// utils

void		free_array(char **arr);
void		free_end(t_data *data);
int			waiting(t_data *data);
void ft_close(int *fd, t_data *data);

#endif