/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:34:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/11 17:05:34 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

// OBJECTIF gerer : ./pipex file1 cmd1 cmd2 file2
// OBJECTIF gerer : ./pipex here_doc limiter file1 cmd1 cmd2 file2

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		i;
	int		status;

	if (ft_is_here_doc(av, &data))
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
	if (data.is_here_doc)
		if (handle_here_doc(&data) == -1)
			return (cleanup_child(&data), 1);
	while (i - data.decorless < data.cmd_count)
	{
		data.cmd = parsing_cmd(&data, i);
		if (looking_using(&data, data.cmd, i))
			return (cleanup_child(&data), 1);
		free_array(data.cmd);
		data.cmd = NULL;
		i++;
	}
	if (data.here_doc_fd >= 0)
	{
		close(data.here_doc_fd);
		data.here_doc_fd = -1;
	}
	status = waiting(&data);
	cleanup_child(&data);
	return (status);
}
