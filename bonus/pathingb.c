/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathingb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:58:38 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/10 13:42:42 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	**find_path(t_data *data)
{
	char	**paths;
	char	*path_var;

	path_var = get_path_var(data);
	if (!path_var || path_var[0] == 0)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (cleanup_child(data),NULL);
	return (add_slash_to_paths(paths));
}

char	*get_path_var(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PATH=", 5) == 0)
			return (data->env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*add_slash(char *path)
{
	char	*new_path;

	if (!path)
		return (NULL);
	new_path = ft_strjoin(path, "/");
	free(path);
	return (new_path);
}

char	**add_slash_to_paths(char **paths)
{
	int	i;

	i = 0;
	if (!paths || !paths[0])
		return (paths);
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
