/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:34:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/02 19:58:34 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// int	main(int ac, char **av)
// {
//     if (ac != 5)
//     {
//         ft_putendl_fd("Error\n", 2);
//         return (0);
//     }
//     ft_init_pipex();
// 	ft_check_args();
// 	ft_parse_cmds();
// 	ft_parse_args();
// 	while ()
// 		ft_exec();
// 	ft_cleanup();
// }
void	init_data(void)
{
}

// OBJECTIF gerer : ./pipex file1 cmd1 cmd2 file2

int	main(int ac, char **av, char **env)
{
	char	**path;
	char	**cmd;
    t_data data;
	int		i;

	i = 1;
    init_data(); // creer un init_data
	path = find_path(env); // garder necessaire pour toute les commandes
	while (i < data.cmd_count)
    {
		cmd = parsing_cmd(av);    
	    looking_using(path, cmd, env, i); // remplacer av[1] par les commandes
    }
    //ajouter le waitpid
    free_end(cmd, path);
	return (0);
}

// int main(int ac, char **av, char **env)
// {
//     // char *args[] = {"ls", "-l", NULL}; //tableau 2d que je renvois premier
//     char *envp[]= {NULL};

//     if (execve("/bin/ls", &av[1], envp) == -1)
//     {
//         perror("execve");
//         exit(1);
//     }
//     return (0);
// }