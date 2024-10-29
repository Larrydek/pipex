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

void	first_child(int pipefd[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
		ft_error("No such file or directory\n", 1);
	close(pipefd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execute_command(argv[2], envp);
	close(infile);
}

void	second_child(int pipefd[2], char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		ft_error("Error occurred when trying to open or create the file\n", 2);
	close(pipefd[1]);
	dup2(outfile, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	if (!argv[3][0])
		ft_error("Command '' not found\n", 127);
	execute_command(argv[3], envp);
	close(outfile);
}

int	daddy_process(int pipefd[2], pid_t pid1, pid_t pid2)
{
	int	status;

	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	return (0);
}

void	ft_error(char *str, int code)
{
	ft_putstr_fd(str, 2);
	exit(code);
}
