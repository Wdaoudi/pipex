/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:42:06 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/06 20:01:57 by wdaoudi-         ###   ########.fr       */
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

// int main()
// {
// 	int fd;

// 	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
// 	dup2(fd, STDOUT_FILENO);
// 	close(fd);
// 	printf("This is printed in example.txt!\n");

// 	return (0);
// }

// int main()
// {
// 	char *args[3];

// 	args[0] = "ls";
// 	args[1] = "-l";
// 	args[2] = NULL;
// 	execve("/bin/ls", args, NULL);
// 	printf("This line will not be executed.\n");

// 	return (0);
// }

// int main()
// {
// 	if (access("example.txt", R_OK) != -1)
// 		printf("I have permission\n");
// 	else
// 		printf("I don't have permission\n");

// 	return (0);
// }

// int main()
// {
// 	if (unlink("example.txt") == 0)
// 		printf("File successfully deleted");
// 	else
// 		printf("Error deleting file");

// 	return (0);
// }

// ex dup 2 et redirection de la sortie
// int	main(void)
// {
// 	int fd;

// 	fd = open("outfile.txt", O_WRONLY | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// 	if (dup2(fd, STDOUT_FILENO) == -1) // fileno =  1 c est la sortie standar
// 	{
// 		perror("dup2");
// 		close(fd);
// 		return (1);
// 	}
// 	printf("texte rediriger vers le outfile\n aaaa");
// 	if (close(fd) == -1)
// 		return (perror("close"), 1);

// 	return (0);
// }

// pipe

// int	main(void)
// {
// 	int pipefd[2];
// 	pid_t pid;
// 	int fd;
// 	char buffer[1024];
// 	ssize_t bytes_read;

// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		return (1);
// 	}

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		return (1);
// 	}
// 	if (pid == 0)
// 	{
// 		close(pipefd[0]);
// 		dup2(pipefd[1], STDOUT_FILENO);
// 		close(pipefd[1]);
// 		execlp("ls", "ls", NULL);
// 		perror("execlp");
// 		return (1);
// 	}
// 	else
// 	{
// 		fd = open("outfile.txt", O_WRONLY | O_TRUNC, 0644);
// 		if (fd == -1)
// 		{
// 			perror("open");
// 			return (1);
// 		}
// 		close(pipefd[1]);
// 		while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0)
// 		{
// 			buffer[bytes_read] = '\0';
// 			dup2(fd, STDOUT_FILENO);
// 			printf("%s", buffer);
// 		}
// 		if (bytes_read == -1)
// 		{
// 			perror("read");
// 		}
// 		close(pipefd[0]);
// 		close(fd);
// 			wait(NULL);
// 	}
// 	return (0);
// }

// chainage de commandes avec pipes

int	main(void)
{
	int pipe1[2], pipe2[2];

	pid_t pid1, pid2, pid3;
	if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid1 == 0) // premier enfant "ls"
	{
		close(pipe1[0]);
		close(pipe2[0]);
		close(pipe2[1]);
		dup2(pipe1[1], STDOUT_FILENO);
		close(pipe1[1]);
		execlp("ls", "ls", NULL);
		perror("ls");
		exit (1);
	}
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork 2");
		return (1);
	}
	if (pid2 == 0) // deuxieme enfant "grep"
	{
		close(pipe1[1]);
		close(pipe2[0]);
		dup2(pipe1[0], STDIN_FILENO);
		dup2(pipe2[1], STDOUT_FILENO);
		close(pipe1[0]);
		close(pipe2[1]);
		execlp("grep", "grep", ".txt", NULL);
		perror("grep");
		exit (1);
	}
	pid3 = fork();
	if (pid3 == -1)
	{
		perror("fork 3");
		return (1);
	}
	if (pid3 == 0) // troisieme enfants(wc -l)
	{
		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[1]);
		dup2(pipe2[0], STDIN_FILENO);
		close(pipe2[0]);
		execlp("wc", "wc", "-l", NULL);
		perror("wc -l");
		exit (1);
	}
	//processus parents fermeture
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	return (0);
}