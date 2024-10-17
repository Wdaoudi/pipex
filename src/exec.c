/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:40:14 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/17 21:13:28 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exec_first(t_data *data, char **cmd, int *fd)
{
	int		fd_first;
	char	*full_path;

	fd_first = -1;
	if (data->is_here_doc)
		fd_first = data->here_doc_fd;
	else
	{
		fd_first = open(data->av[1], O_RDONLY);
		if (fd_first == -1)
			(ft_close(&fd_first, &fd[0], &fd[1], data), ft_fd_first(data));
	}
	if (dup2(fd_first, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	ft_close(&fd_first, &fd[0], &fd[1], data);
	full_path = have_access(data, cmd[0]);
	if (full_path == NULL)
		sub_exec(data, cmd);
	execve(full_path, cmd, data->env);
	// perror(full_path);
	ft_putendl_fd("Execve failed", STDERR_FILENO);
	free(full_path);
	cleanup_child(data);
	exit(1);
}

void	ft_exec_last(t_data *data, char **cmd)
{
	int		fd_last;
	char	*full_path;

	if (data->is_here_doc)
		fd_last = open(data->av[data->ac - 1], O_WRONLY | O_CREAT | O_APPEND,
				0644);
	else
		fd_last = open(data->av[data->ac - 1], O_WRONLY | O_CREAT | O_TRUNC,
				0644);
	if (fd_last == -1)
		ft_impossible(data);
	if (dup2(data->prev_fd, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(fd_last, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	ft_close(&fd_last, &data->prev_fd, NULL, data);
	full_path = have_access(data, cmd[0]);
	if (full_path == NULL)
		sub_exec(data, cmd);
	execve(full_path, cmd, data->env);
	ft_putendl_fd("Execve failed", STDERR_FILENO);
	free(full_path);
	cleanup_child(data);
	exit(1);
}

void	ft_exec(t_data *data, char **cmd, int fd[])
{
	char	*full_path;

	dup2(data->prev_fd, STDIN_FILENO);
	if (dup2(data->prev_fd, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	ft_close(&data->prev_fd, &fd[0], &fd[1], data);
	full_path = have_access(data, cmd[0]);
	if (full_path == NULL)
		sub_exec(data, cmd);
	execve(full_path, cmd, data->env);
	ft_putendl_fd("Execve failed", STDERR_FILENO);
	free(full_path);
	cleanup_child(data);
	exit(1);
}

void	ft_impossible(t_data *data)
{
	// ft_putstr_fd("pipex: ", STDERR_FILENO);
	// ft_putstr_fd(data->av[data->ac - 1], STDERR_FILENO);
	perror(data->av[data->ac - 1]);
	cleanup_child(data);
	exit(1);
}
