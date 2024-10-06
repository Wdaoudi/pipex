/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:20:58 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/06 18:09:59 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_end(t_data *data)
{
	if (data->path)
		free_array(data->path);
	if (data->fd_in != -1)
		close(data->fd_in);
	if (data->fd_out != -1)
		close(data->fd_out);
	// if (data->pid)
	// 	free(data->pid);
}

int	waiting(t_data *data)
{
	int i;
	int status;
	i = 0;
	status = 0;
	while (i < data->cmd_count)
	{
		waitpid(data->pid[i], &status, 0);
		i++;
	}
	free_end(data);
	return (status);
}

void ft_close(int *fd, t_data *data)
{
	if (*fd == -1 || *fd == STDIN_FILENO || *fd == STDERR_FILENO || *fd == STDOUT_FILENO)
		return;
	if (close(*fd) == -1)
	{
		*fd = -1;
		free_end(&data);
	}
	*fd = -1;
}