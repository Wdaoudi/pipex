/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/03 19:57:07 by wdaoudi-         ###   ########.fr       */
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
	data->av = av;
	data->env = env;
	data->ac = ac;
	data->path = find_path(data);
	data->cmd_count = ac - 2;
	data->error = 0;
	opening_file(data);
	data->pid = malloc(sizeof(pid_t) * data->cmd_count);
	if (!data->pid)
		return ;

}

void	opening_file(t_data *data)
{
	int	fd_in;
	int	fd_out;

	fd_in = open(data->av[1], O_RDONLY);
	if (fd_in == -1)
	{
		ft_putstr_fd(data->av[1], STDERR_FILENO);
		ft_putendl_fd(": No such file or directory",STDERR_FILENO);
		data->error = 1;
		return ;
	}
	fd_out = open(data->av[data->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fd_out == -1)
	{
		perror("Error opening output file");
		close(data->fd_in);
		data->error = 1;
		return ;
	}

}
