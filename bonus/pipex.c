/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:34:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/08 18:46:15 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

// OBJECTIF gerer : ./pipex file1 cmd1 cmd2 file2
void	submain(t_data *data, int i)
{
	while (i <= data->cmd_count)
	{
		data->cmd = parsing_cmd(&data, i);
		if (looking_using(&data,data->cmd, i))
			return (cleanup_child(&data), 1);
		free_array(data->cmd);
		data->cmd = NULL;
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		i;
	int		status;
	bool	is_here_doc;

	if (ac < 5)
		return (ft_putendl_fd("Error: Not enough arguments", 2), 1);
	is_here_doc = ft_is_here_doc(is_here_doc, av, ac);
	i = 2;
	init_data(&data, ac, av, env);
	init_data2(&data, is_here_doc);
	data.is_here_doc = is_here_doc;
	submain(&data, i);
	// while (i <= data.cmd_count)
	// {
	// 	data.cmd = parsing_cmd(&data, i);
	// 	if (looking_using(&data, data.cmd, i))
	// 		return (cleanup_child(&data), 1);
	// 	free_array(data.cmd);
	// 	data.cmd = NULL;
	// 	i++;
	// }
	if (data.prev_fd != -1)
		close(data.prev_fd);
	status = waiting(&data);
	cleanup_child(&data);
	return (status);
}
