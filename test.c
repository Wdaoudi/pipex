/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:42:06 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/30 17:45:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// fork

// int	main(void)
// {
// 	pid_t pid = fork();
// 	if (pid < 0)
// 	{
// 		printf("erreur lors du fork\n");
// 		return (1);
// 	}
// 	if (pid == 0)
// 	{
// 		printf("jr suis l enfant avec l ID: %d\n", pid);
// 	}
// 	else
// 		printf("je suis le parent avce l ID: %d\n", pid);
// 	return (0);
// }

// int	main(void)
// {
// 	int i;
// 	pid_t pid = fork();

// 	i = 0;
// 	if (pid < 0)
// 	{
// 		printf("erreur lors du fork\n");
// 		return (1);
// 	}
// 	else if (pid != 0)
// 	{
// 		printf("niveau du fork =%d et pid = %d\n", i, pid);
// 	}
// 	else
// 	{
// 		i++;
// 		printf("niveau du fork =%d et pid = %d\n", i, getpid());
// 		fork();
// 		i++;
// 		printf("niveau du fork =%d et pid = %d\n", i, getpid());
// 	}
//     return (0);
// }

// pipe

// int	main(void)
// {
// 	pid_t	pid;
// 	char	buf[20];

// 	int pipefd[2]; // == tbleau conteant deux int  qui permettra de recuperer
// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		exit(1);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(1);
// 	}
// 	if (pid == 0) // processus enfant qui a un pid a 0
// 	{
// 		close(pipefd[1]); // ferme l extremite d ecriture
// 		read(pipefd[0], buf, sizeof(buf));
// 		printf("enfant a recu: %s\n", buf);
// 		close(pipefd[0]);
// 	}
// 	else // processus parent
// 	{
// 		close(pipefd[0]); // ferme l extremite de lecture
// 		write(pipefd[1], "Hello child", 11);
// 		close(pipefd[1]);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	int		pipefd[2];
// 	pid_t	pid;
// 	char	buf[20];

// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		exit(1);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(1);
// 	}
// 	if (pid == 0)
// 	{
// 		close(pipefd[1]);
// 		read(pipefd[0], buf, sizeof(buf));
// 		printf("enfant a recu %s\n", buf);
// 		close(pipefd[0]);
// 	}
// 	else
// 	{
// 		close(pipefd[0]);
// 		write(pipefd[1], "42", 2);
// 		close(pipefd[1]);
// 	}
// 	return (0);
// }
// struct		CalcData
// {
// 	int		num1;
// 	int		num2;
// 	char	operator;
// };

// int	main(void)
// {
// 	int				pipefd[2];
// 	pid_t			pid;
// 	struct CalcData	data;
// 	int				result;

// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		exit(1);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(1);
// 	}
// 	if (pid == 0) // Processus enfant (calculateur)
// 	{
// 		close(pipefd[1]); // Ferme l'extrémité d'écriture
// 		// Lit les données du pipe
// 		read(pipefd[0], &data, sizeof(struct CalcData));
// 		// Effectue le calcul
// 		switch (data.operator)
// 		{
// 		case '+':
// 			result = data.num1 + data.num2;
// 			break ;
// 		case '-':
// 			result = data.num1 - data.num2;
// 			break ;
// 		case '*':
// 			result = data.num1 * data.num2;
// 			break ;
// 		case '/':
// 			if (data.num2 != 0)
// 			{
// 				result = data.num1 / data.num2;
// 			}
// 			else
// 			{
// 				printf("Erreur: Division par zéro\n");
// 				exit(1);
// 			}
// 			break ;
// 		default:
// 			printf("Opérateur non reconnu\n");
// 			exit(1);
// 		}
// 		printf("Résultat: %d %c %d = %d\n", data.num1, data.operator, data.num2,
// 			result);
// 		close(pipefd[0]);
// 		exit(0);
// 	}
// 	else // Processus parent
// 	{
// 		close(pipefd[0]); // Ferme l'extrémité de lecture
// 		// Demande les entrées à l'utilisateur
// 		printf("Entrez le premier nombre: ");
// 		scanf("%d", &data.num1);
// 		printf("Entrez l'opérateur (+, -, *, /): ");
// 		scanf(" %c", &data.operator);
// 		printf("Entrez le deuxième nombre: ");
// 		scanf("%d", &data.num2);
// 		// Envoie les données via le pipe
// 		write(pipefd[1], &data, sizeof(struct CalcData));
// 		close(pipefd[1]);
// 	}
// 	return (0);
// }
