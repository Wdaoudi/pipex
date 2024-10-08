/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:04:51 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/08 18:47:46 by wdaoudi-         ###   ########.fr       */
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
