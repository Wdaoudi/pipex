/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/08 18:29:38 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	**parsing_cmd(t_data *data, int i)
{
	char	**cmd;

	cmd = ft_split(data->av[i], ' ');
	if (!cmd)
		return (cleanup_child(data), NULL);
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
	if (!data->path)
		return (cleanup_child(data));
	data->cmd_count = ac - 2;
	data->prev_fd = -1;
	data->pid = malloc(sizeof(pid_t) * data->cmd_count);
	if (!data->pid)
		return (cleanup_child(data));
	while (i < data->cmd_count)
	{
		data->pid[i] = -1;
		i++;
	}
}

void init_data2(t_data *data, bool is_here_doc)
{
	
}
