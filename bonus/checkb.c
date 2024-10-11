/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:53:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/11 18:34:45 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	redirect(t_data *data, int i, char **cmd, int fd[])
{
	if (i == data->decorless)
		ft_exec_first(data, cmd, fd);
	else if (i == data->ac - 2)
		ft_exec_last(data, cmd);
	else
		ft_exec(data, cmd, fd);
}

int	looking_using(t_data *data, char **cmd, int i)
{
	int	fd[2];

	if (i - data->decorless < data->cmd_count) 
		if (pipe(fd) == -1)
			return (ft_putendl_fd("Error creating pipe", STDERR_FILENO), 1);
	data->pid[i - data->decorless] = fork();
	if (data->pid[i - data->decorless] < 0)
		return (ft_putendl_fd("Error forking", STDERR_FILENO), 1);
	else if (data->pid[i - data->decorless] == 0)
	{
		redirect(data, i, cmd, fd);
		return (1);
	}
	if (data->prev_fd != -1)
	{
		close(data->prev_fd);
		data->prev_fd = -1;
	}
	if (i- data->decorless < data->cmd_count)
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
	if (!cmd || cmd[0] == '\0')
		return (NULL);
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
	if (cmd && cmd[0])
	{
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
	}
	else
		ft_putendl_fd("empty command", STDERR_FILENO);
}
