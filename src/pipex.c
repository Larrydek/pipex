/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:08:33 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 01:08:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void pipex(char **argv, char **envp)
{
	int pipefd[2];
	pid_t pid1;
	pid_t pid2;

	pipe(pipefd);
	pid1 = fork();
	if (pid1 == 0)
		first_child(pipefd, argv, envp);  // Maneja cmd1

	pid2 = fork();
	if (pid2 == 0)
		second_child(pipefd, argv, envp); // Maneja cmd2

	daddy_process(pipefd, pid1, pid2);
}
