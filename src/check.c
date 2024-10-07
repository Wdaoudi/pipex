/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:53:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/07 19:32:57 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	redirect(t_data *data, int i, char **cmd, int fd[])
{
	if (i == 2)
		ft_exec_first(data, cmd, fd);
	else if (i == data->ac - 2)
		ft_exec_last(data, cmd);
	else
		ft_exec(data, cmd, fd);
}

int	looking_using(t_data *data, char **cmd, int i)
{
	int	fd[2];

	if (i < data->ac - 2)
		if (pipe(fd) == -1)
			return (ft_putendl_fd("Error creating pipe", STDERR_FILENO),
				cleanup_child(data, cmd), 1);
	data->pid[i - 2] = fork();
	if (data->pid[i - 2] < 0)
		return (ft_putendl_fd("Error forking", STDERR_FILENO),
			cleanup_child(data, cmd), 1);
	else if (data->pid[i - 2] == 0)
	{
		redirect(data, i, cmd, fd);
		cleanup_child(data,cmd);
		exit(1);
	}
	if (data->prev_fd != -1)
		close(data->prev_fd);
	if (i < data->ac - 2)
	{
		close(fd[1]);
		data->prev_fd = fd[0];
	}
	else
		data->prev_fd = -1;
	return (0);
}

char	*have_access(t_data *data, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (data->path[i])
	{
		full_path = ft_strjoin(data->path[i], cmd);
		if (!full_path)
		{
			ft_putstr_fd("Error: Memory allocation failed\n", STDERR_FILENO);
			return (NULL);
		}
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

void	path_not_found(char **cmd)
{
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
}
