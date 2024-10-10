/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:34:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/10 15:50:01 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

// OBJECTIF gerer : ./pipex file1 cmd1 cmd2 file2

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		i;
	int		status;
	int		is_here_doc;

	is_here_doc = ft_is_here_doc(av, &data);
	if (is_here_doc)
	{
		i = 3;
		if (ac < 6)
			return (ft_putendl_fd("Error: Not enough arguments", 2), 1);
	}
	else
	{
		i = 2;
		if (ac < 5)
			return (ft_putendl_fd("Error: Not enough arguments", 2), 1);
	}
	init_data(&data, ac, av, env);
	while (i <= data.cmd_count)
	{
		data.cmd = parsing_cmd(&data, i);
		if (looking_using(&data, data.cmd, i))
			return (cleanup_child(&data), 1);
		free_array(data.cmd);
		data.cmd = NULL;
		i++;
	}
	if (data.prev_fd != -1)
		close(data.prev_fd);
	status = waiting(&data);
	cleanup_child(&data);
	return (status);
}
