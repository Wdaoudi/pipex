/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:53:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/03 18:45:29 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	looking_using(t_data *data, char **cmd, int i)
{
	char	*full_path;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("Error forking", STDERR_FILENO), exit(1);
		return (1);
	}
	else if (pid == 0)
	{
		full_path = have_access(data, cmd[0]);
		if (full_path == NULL)
			return (path_not_found(cmd), 1);
		execve(full_path, cmd, data->env);
		ft_putendl_fd("Execve failed", STDERR_FILENO);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
			return (1);
	}
	return (0);
}

char	*have_access(t_data *data, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (data->path[i])
	{
		full_path = ft_strjoin(data->path[i], cmd);
		if (!full_path)
		{
			ft_putstr_fd("Error: Memory allocation failed\n", STDERR_FILENO);
			return (NULL);
		}
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}
void	path_not_found(char **cmd)
{
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
}