/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:53:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 15:14:50 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	redirect(t_data *data, int i, char **cmd, int fd[])
{
	if (i == data->decorless)
		ft_exec_first(data, cmd, fd);
	else if (i == data->ac - 2)
	{
		close(fd[0]);
		close(fd[1]);
		ft_exec_last(data, cmd);
	}
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
	if (i - data->decorless < data->cmd_count)
		sub_looking(fd, data);
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
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	while (data->path && data->path[i])
	{
		full_path = ft_strjoin(data->path[i], cmd);
		if (!full_path)
			return (ft_putstr_fd("Error: Memory allocation failed\n",
					STDERR_FILENO), NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

static char	*build_error_msg(char **cmd)
{
	char	*error_msg;
	char	*cmd_str;
	char	*temp;

	if (cmd && cmd[0])
		cmd_str = ft_strdup(cmd[0]);
	else
		cmd_str = ft_strdup("");
	if (!cmd_str)
		return (NULL);
	error_msg = ft_strjoin("pipex: ", cmd_str);
	free(cmd_str);
	if (!error_msg)
		return (NULL);
	temp = error_msg;
	error_msg = ft_strjoin(error_msg, ": command not found\n");
	free(temp);
	return (error_msg);
}

void	path_not_found(char **cmd)
{
	char	*error_msg;

	error_msg = build_error_msg(cmd);
	if (!error_msg)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", STDERR_FILENO);
		return ;
	}
	ft_putstr_fd(error_msg, STDERR_FILENO);
	free(error_msg);
}

// void	path_not_found(char **cmd)
// {
// 	ft_putstr_fd("pipex: ", STDERR_FILENO);
// 	if (cmd && cmd[0])
// 		ft_putstr_fd(cmd[0], STDERR_FILENO);
// 	else
// 		ft_putstr_fd("", STDERR_FILENO);
// 	ft_putendl_fd("command not found", STDERR_FILENO);
// }