/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:57:51 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/02 19:43:55 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	**av;
	int		cmd_count;
	pid_t	pid;

}			t_data;

// pathing

char		**find_path(char **env);
char		*get_path_var(char **env);
char		*add_slash(char *path);
char		**add_slash_to_paths(char **paths);

// parsing + check

char		*have_access(char **path, char *cmd);
void		looking_using(char **path, char **cmd, char **env);
char		**parsing_cmd(char **av);

// utils

void		free_array(char **arr);
void		free_end(char **arr1, char **arr2);

#endif