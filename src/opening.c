/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:43:50 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/07 19:31:35 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_opening(t_data *data)
{
	ft_putstr_fd(data->av[1], STDERR_FILENO);
	ft_putendl_fd(": No such file or directory", STDERR_FILENO);
}

void	cleanup_child(t_data *data, char **cmd)
{
	if (data->path)
		free_array(data->path);
	if (data->pid)
		free(data->pid);
	if (cmd)
		free_array(cmd);
	free_end(data);
	if (data->prev_fd != -1)
		close(data->prev_fd);
}
