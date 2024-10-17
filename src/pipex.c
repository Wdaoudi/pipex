/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:34:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/17 16:28:15 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_arguments(int ac, char **av, t_data *data)
{
	if (ac < 5)
		return (ft_putendl_fd("Error: Not enough arguments", 2), 1);
	if (ft_is_here_doc(av, data))
	{
		data->decorless = 3;
		if (ac < 6)
			return (ft_putendl_fd("Error: Not enough arguments", 2), 1);
	}
	else
	{
		data->decorless = 2;
		if (ac < 5)
			return (ft_putendl_fd("Error: Not enough arguments", 2), 1);
	}
	return (0);
}

int	setup_here_doc(t_data *data)
{
	if (data->is_here_doc)
	{
		data->here_doc_fd = handle_here_doc(data);
		if (data->here_doc_fd == -1)
			return (cleanup_child(data), 1);
	}
	return (0);
}

int	execute_commands(t_data *data)
{
	int	i;

	i = data->decorless;
	while (i - data->decorless < data->cmd_count)
	{
		data->cmd = parsing_cmd(data, i);
		if (looking_using(data, data->cmd, i))
			return (cleanup_child(data), 1);
		free_array(data->cmd);
		data->cmd = NULL;
		i++;
	}
	return (0);
}

void	cleanup_and_wait(t_data *data, int *status)
{
	if (data->is_here_doc == 1 && data->here_doc_fd >= 0)
	{
		close(data->here_doc_fd);
		data->here_doc_fd = -1;
	}
	*status = waiting(data);
	cleanup_child(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		status;

	if (check_arguments(ac, av, &data))
		return (1);
	init_data(&data, ac, av, env);
	if (setup_here_doc(&data))
		return (1);
	if (execute_commands(&data))
		return (1);
	cleanup_and_wait(&data, &status);
	return (status);
}
