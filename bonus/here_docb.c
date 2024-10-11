/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_docb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:44:19 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/11 18:36:05 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_is_here_doc(char **av, t_data *data)
{
	data->is_here_doc = 0;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		data->limiter = av[2];
		data->is_here_doc = 1;
	}
	return (data->is_here_doc);
}
int	handle_here_doc(t_data *data)
{
	char	*line;
	int		pipe_fd[2];
	int		continue_reading;

	if (pipe(pipe_fd) == -1)
		return (perror("pipe"), -1);
	continue_reading = 1;
	while (continue_reading)
	{
		ft_putstr_fd(">", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			continue_reading = 0;
		else if (ft_strncmp(line, data->limiter, ft_strlen(data->limiter)) == 0
			&& line[ft_strlen(data->limiter)] == '\n')
		{
			free(line);
			continue_reading = 0;
		}
		else
		{
			ft_putstr_fd(line, pipe_fd[1]);
			// ft_putstr_fd("\n", pipe_fd[1]);
			free(line);
		}
	}
	free(line);
	close(pipe_fd[1]);
	if (pipe_fd[0] == -1)
		return (perror("Error with here_doc pipe"), -1);
	data->here_doc_fd = pipe_fd[0];
	return (pipe_fd[0]);
}
// char	*here_doc_on_first_exec(t_data *data, char **cmd, int *fd)
// {
// 	char *full_path;
// 	int fd_first;

// 	fd_first = data->here_doc_fd;
// 	if (fd_first == -1)
// 		fd_first = ft_fd_first(fd_first, data);
// 	// if (dup2(fd_first, STDIN_FILENO) == -1)
// 	// 	(EXIT_FAILURE);
// 	if (dup2(fd_first, STDIN_FILENO) == -1)
// 		(EXIT_FAILURE);
// 	if (dup2(fd[1], STDOUT_FILENO) == -1)
// 		(EXIT_FAILURE);
// 	ft_close(&fd_first, &fd[0], &fd[1], data);
// 	full_path = have_access(data, cmd[0]);
// 	if (full_path == NULL)
// 	{
// 		path_not_found(cmd);
// 		cleanup_child(data);
// 		exit(127);
// 	}
// 	return (full_path);
// }