/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_docb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:44:19 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/10 19:17:44 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_is_here_doc(char **av, t_data *data)
{
	int	i;

	i = 0;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 1;
		data->limiter = av[2];
		data->is_here_doc = i;
	}
	return (i);
}
int	handle_here_doc(t_data *data)
{
	char *line;
	int pipe_fd[2];
	int continue_reading;

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
			// ft_putstr_fd(line, pipe_fd[1]);
			free(line);
			continue_reading = 0;
		}
		else
		{
			ft_putstr_fd(line, pipe_fd[1]);
			free(line);
		}
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
