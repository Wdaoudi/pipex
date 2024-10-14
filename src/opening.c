/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:43:50 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/14 20:10:23 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_opening(t_data *data)
{
	perror(data->av[1]);
}

void	cleanup_child(t_data *data)
{
	if (data->path)
		free_array(data->path);
	if (data->pid)
		free(data->pid);
	if (data->cmd)
		free_array(data->cmd);
	if (data->prev_fd >= 0)
	{
		close(data->prev_fd);
		data->prev_fd = -1;
	}
	if (data->is_here_doc == 1 && data->here_doc_fd >= 0)
	{
		close(data->here_doc_fd);
		data->here_doc_fd = -1;
	}
}
