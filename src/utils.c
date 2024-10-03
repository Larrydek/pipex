/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:04:26 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 14:04:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void init_pipes(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("init pipe error");
		exit(EXIT_FAILURE);
	}
}

void first_child(int pipefd[2], char **argv)
{
	int infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror("infile error");
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);		// Redirige entrada a infile
	dup2(pipefd[1], STDOUT_FILENO);	// Redirige salida al pipe
	close(pipefd[0]);				// Cierra el extremo de lectura
	execute_command(argv[2]);
}

void second_child(int pipefd[2], char **argv)
{
	int outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("outfile error");
		exit(EXIT_FAILURE);
	}
	dup2(pipefd[0], STDIN_FILENO);  // Redirige entrada desde el pipe
	dup2(outfile, STDOUT_FILENO);   // Redirige salida a outfile
	close(pipefd[1]);               // Cierra el extremo de escritura
	execute_command(argv[3]);
}

void daddy_process(int pipefd[2], pid_t pid1, pid_t pid2)
{
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
