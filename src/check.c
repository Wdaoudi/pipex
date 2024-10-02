/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:53:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/02 19:58:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	looking_using(char **path, char **cmd, char **env, int i)
{
	char	*full_path;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("Error forking", STDERR_FILENO),
		exit(1);
	}
	else if (pid == 0)
	{
		full_path = have_access(path, cmd[0]);
		if (full_path == NULL)
			return ;
		execve(full_path, cmd, env);
		ft_putendl_fd("Execve failed", STDERR_FILENO);
		exit(1);
	}
	// else
	// {
	// 	waitpid(-1, NULL, 0);
	// 	return;
	// }
}

char	*have_access(char **path, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (path[i])
	{
		full_path = ft_strjoin(path[i], cmd);
		if (!full_path)
		{
			ft_putstr_fd("Error: Memory allocation failed\n", 2);
			return (NULL);
		}
		if (access(full_path, F_OK | X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL);
}
