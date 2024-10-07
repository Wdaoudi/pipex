/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/07 19:30:18 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**parsing_cmd(t_data data, int i)
{
	char	**cmd;

	cmd = ft_split(data.av[i], ' ');
	return (cmd);
}

void	init_data(t_data *data, int ac, char **av, char **env)
{
	int	i;

	i = 0;
	data->av = av;
	data->env = env;
	data->ac = ac;
	data->path = find_path(data);
	data->cmd_count = ac - 2;
	data->prev_fd = -1;
	data->pid = malloc(sizeof(pid_t) * data->cmd_count);
	if (!data->pid)
		return (free_end(data),cleanup_child(data,data->path));
	while (i < data->cmd_count)
	{
		data->pid[i] = -1;
		i++;
	}
}
