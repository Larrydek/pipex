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

int main(int argc, char **argv, char **envp)
{
	int pipefd[2];
	int	daddy_code;
	pid_t pid1;
	pid_t pid2;
	if (argc != 5)
		ft_error("Error: structure expected ---> ./pipex infile cmd1 cmd2 outfile\n", 127);

	pipe(pipefd);
	pid1 = fork();
	if (pid1 == 0)
		first_child(pipefd, argv, envp);

	pid2 = fork();
	if (pid2 == 0)
		second_child(pipefd, argv, envp);
	daddy_code = daddy_process(pipefd, pid1, pid2);
	//printf("error_code: %i\n", daddy_code);
	return (daddy_code);
}
