/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:43:50 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/06 18:16:14 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_opening(t_data *data)
{
	ft_putstr_fd(data->av[1], STDERR_FILENO);
	ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	data->error = 1;
	return ;
}