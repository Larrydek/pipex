/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:00:03 by marvin            #+#    #+#             */
/*   Updated: 2024/09/01 18:00:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../lib/libft/inc/libft.h"
# include "../lib/printf/inc/ft_printf.h"

void	init_pipes(int *pipefd);
void	first_child(int pipefd[2], char **argv, char **envp);
void	second_child(int pipefd[2], char **argv, char **envp);
int		daddy_process(int pipefd[2], pid_t pid1, pid_t pid2);
void	execute_command(char *cmd, char **envp);
char	*get_path(char *cmd, char **envp);
char	*find_cmd_in_path(char *cmd, char **all_paths);
void	ft_error(char *str, int code);

#endif