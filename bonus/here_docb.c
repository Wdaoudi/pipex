/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:04:51 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/08 19:35:26 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

bool	ft_is_here_doc(bool is_here_doc, char **av, int ac)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
            if (ac < 6)
            {
                ft_putendl_fd("Error: Not enough argument for here_doc", 2);
                EXIT_FAILURE;
            }
            is_here_doc = true;
        }
    else
		is_here_doc = false;
	return (is_here_doc);
}

int handle_here_doc(t_data *data, char *limiter)
{
    char *line;
    int pipe_fd[2];
    int continue_reading;

    if (pipe(pipe_fd) == -1)
        return(perror("pipe") , -1);
    continue_reading = 1;
    while (continue_reading)
    {
        ft_putstr_fd(">", STDOUT_FILENO);
        line  = get_next_line(STDIN_FILENO);
        if (!line)
            continue_reading = 0;
        else if (ft_strncmp(line, limiter,ft_strlen(limiter)) == 0 && line[ft_strlen(limiter)] == '\n')
        {
            ft_putstr_fd(line, pipe_fd[1]);
            free(line);
        }
    }
    close(pipe_fd[1]);
    return (pipe_fd[0]);
}
