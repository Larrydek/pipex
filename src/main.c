/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:30:14 by marvin            #+#    #+#             */
/*   Updated: 2024/09/01 15:30:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main(int argc, char **argv)
{
	int infile;
	int outfile;
	int pipefd[2];
	int pid;

	// Comprobación de la cantidad de argumentos
	if (argc != 5)
		return (ft_printf("Error: No hay 5 argumentos\n"), NULL);
	pid = fork();
	if (pid > 0)
		infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		return (ft_printf("Error: No hay 5 argumentos\n"), NULL);
	pid = fork();
	if (fork() == 0)
		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("Error al abrir archivo de salida");
		close(infile);
		return (NULL);
	}
	close(infile);
	close(outfile);

	return (EXIT_SUCCESS);
}

