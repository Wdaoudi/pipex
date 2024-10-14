/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/14 17:52:13 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
	sub_init(data, av, env, ac);
	data->path = find_path(data);
	if (!data->path)
		return (cleanup_child(data));
	if (data->is_here_doc)
	{
		data->cmd_count = ac - 4;
		data->decorless = 3;
	}
	else
	{
		data->cmd_count = ac - 3;
		data->decorless = 2;
	}
	data->pid = malloc(sizeof(pid_t) * data->cmd_count);
	if (!data->pid)
		return (cleanup_child(data));
	while (i < data->cmd_count)
	{
		data->pid[i] = -1;
		i++;
	}
}

void	sub_exec(t_data *data, char **cmd)
{
	path_not_found(cmd);
	cleanup_child(data);
	exit(127);
}

void	sub_init(t_data *data, char **av, char **env, int ac)
{
	data->av = av;
	data->env = env;
	data->ac = ac;
	data->prev_fd = -1;
	data->cmd = NULL;
}
