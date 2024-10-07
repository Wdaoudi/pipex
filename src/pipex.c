/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:34:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/07 18:58:38 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// OBJECTIF gerer : ./pipex file1 cmd1 cmd2 file2

int	main(int ac, char **av, char **env)
{
	char	**path;
	char	**cmd;
	t_data	data;
	int		i;
	int		status;

	if (ac < 5)
		return (0);
	i = 2;
	init_data(&data, ac, av, env);
	while (i <= data.cmd_count)
	{
		cmd = parsing_cmd(data, i);
		if (looking_using(&data, cmd, i))
			return (free_array(cmd), free_end(&data), 1);
		free_array(cmd);
		i++;
	}
	status = waiting(&data);
	free_end(&data);
	return (status);
}
