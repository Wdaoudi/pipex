/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:44:19 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/14 17:52:03 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (perror("pipe"), -1);
	process_here_doc_input(data, pipe_fd);
	close(pipe_fd[1]);
	if (pipe_fd[0] == -1)
		return (perror("Error with here_doc pipe"), -1);
	data->here_doc_fd = pipe_fd[0];
	return (pipe_fd[0]);
}

void	process_here_doc_input(t_data *data, int pipe_fd[2])
{
	char	*line;
	int		continue_reading;
	char	*final_cleanup;

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
			free(line);
		}
	}
	final_cleanup = get_next_line(-1);
	free(final_cleanup);
}
