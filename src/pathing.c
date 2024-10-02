/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:58:38 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/02 19:44:14 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**find_path(char **env)
{
	char	**paths;
	char	*path_var;

	path_var = get_path_var(env);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	return (add_slash_to_paths(paths));
}
char	*get_path_var(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*add_slash(char *path)
{
	char	*new_path;

	new_path = ft_strjoin(path, "/");
	free(path);
	return (new_path);
}

char	**add_slash_to_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		paths[i] = add_slash(paths[i]);
		if (!paths[i])
		{
			free_array(paths);
			return (NULL);
		}
		i++;
	}
	return (paths);
}
