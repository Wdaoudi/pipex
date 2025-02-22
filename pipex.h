/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:57:51 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/17 19:35:47 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <errno.h>
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
	char	**path;
	int		ac;
	int		cmd_count;
	int		cmd_start;
	char	**cmd;
	pid_t	*pid;
	int		prev_fd;
	int		is_here_doc;
	int		decorless;
	char	*limiter;
	int		here_doc_fd;
}			t_data;

// pathing

int			find_path(t_data *data);
char		*get_path_var(t_data *data);
char		*add_slash(char *path);
char		**add_slash_to_paths(char **paths);
void		handle_env_i(t_data *data);
void		re_init_after_handle(t_data *data);

// parsing + check

void		init_data(t_data *data, int ac, char **av, char **env);
void		init_data2(t_data *data, bool is_here_doc);
void		opening_file(t_data *data);
char		*have_access(t_data *data, char *cmd);
char		**parsing_cmd(t_data *data, int i);
void		path_not_found(char **cmd);

// exec
int			looking_using(t_data *data, char **cmd, int i);
void		sub_looking(int *fd, t_data *data);
void		redirect(t_data *data, int i, char **cmd, int *fd);
void		ft_exec_first(t_data *data, char **cmd, int *fd);
void		ft_exec_last(t_data *data, char **cmd);
void		ft_exec(t_data *data, char **cmd, int *fd);

// errror

void		error_opening(t_data *data);
int			ft_fd_first(t_data *data);
void		ft_impossible(t_data *data);

// utils

void		cleanup_child(t_data *data);
void		free_array(char **arr);
void		free_end(t_data *data);
int			waiting(t_data *data);
void		ft_close(int *fd1, int *fd2, int *fd3, t_data *data);

// reduction de focntion

int			check_arguments(int ac, char **av, t_data *data);
int			setup_here_doc(t_data *data);
int			execute_commands(t_data *data);
void		cleanup_and_wait(t_data *data, int *status);
void		sub_exec(t_data *data, char **cmd);
void		sub_init(t_data *data, char **av, char **env, int ac);

// here_doc

int			ft_is_here_doc(char **av, t_data *data);
int			handle_here_doc(t_data *data);
void		process_here_doc_input(t_data *data, int pipe_fd[2]);
char		*here_doc_on_first_exec(t_data *data, char **cmd, int *fd);

#endif