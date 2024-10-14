/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:20:58 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/13 17:07:35 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_end(t_data *data)
{
	if (data->path)
		free_array(data->path);
	if (data->pid)
		free(data->pid);
	if (data->cmd)
		free_array(data->cmd);
}

void	ft_close(int *fd1, int *fd2, int *fd3, t_data *data)
{
	if (fd1 && *fd1 != -1 && *fd1 > 2)
	{
		if (close(*fd1) == -1)
			perror("close");
		*fd1 = -1;
	}
	if (fd2 && *fd2 != -1 && *fd2 > 2)
	{
		if (close(*fd2) == -1)
			perror("close");
		*fd2 = -1;
	}
	if (fd3 && *fd3 != -1 && *fd3 > 2)
	{
		if (close(*fd3) == -1)
			perror("close");
		*fd3 = -1;
	}
	(void)data;
}

int	ft_fd_first(t_data *data)
{
	error_opening(data);
	// fd_first = open("/dev/null", O_RDONLY);
	// if (fd_first == -1)
	// {
	// 	perror("open");
	// 	exit(1);
	// }
	// return (fd_first);
	exit(1);
}

int	waiting(t_data *data)
{
	int	i;
	int	status;
	int	last_status;

	last_status = 0;
	i = 0;
	while (i < data->cmd_count)
	{
		if (waitpid(data->pid[i], &status, 0) > 0)
		{
			if (WIFEXITED(status))
				last_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				last_status = 128 + WTERMSIG(status);
		}
		i++;
	}
	return (last_status);
}

/*
WEXITSTATUS extrait le code
 de sortie de l enfant

 WIFEXITED(status) verifie si le processus
  enfant termine normal

WIFSIGNALED verifie si l enfant s est
terminee a cause d un signal d interruption de maniere anormale

WTERMSIG extrait le numero du signal qui a
 cause la terminaison

+128 convention qui permet de distinguee les signal des codes de sortie normaux
 */