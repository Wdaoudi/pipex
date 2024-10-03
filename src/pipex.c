/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:34:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/03 20:03:55 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// OBJECTIF gerer : ./pipex file1 cmd1 cmd2 file2

int	main(int ac, char **av, char **env)
{
	char **path;
	char **cmd;
	t_data data;
	int i;

	i = 2;
	init_data(&data, ac, av, env);
	if (data.error)
		return (1);
	while (i <= data.cmd_count)
	{
		cmd = parsing_cmd(data, i);
		if (looking_using(&data, cmd, i)) // remplacer av[1] par les commandes
			return (free(cmd), free_end(&data), 1);
		free_array(cmd);
		i++;
	}
	return (waiting(&data));
	// waitpid(data.pid, &status, 0);
	// if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
	// 	return (1);
	// free_end(&data);
	// return (0);
}
