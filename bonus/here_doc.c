/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:44:19 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/10 14:06:19 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_is_here_doc(char **av, t_data *data)
{
	int i;

	i = 0;
	if (ft_strnmcp(av[1], "here_doc", 8) == 0)
	{
        i = 1;
        data->limiter = av[2];
        data->is_here_doc = i;
    }
    return (i);
}