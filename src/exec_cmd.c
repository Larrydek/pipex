/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:07:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/18 01:07:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	printf("path: %s\n", cmd);
	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("Error in split\n");
		exit(EXIT_FAILURE);
	}
	path = get_path(args[0], envp);
	if (!path)
	{
		perror("Command not found\n");
		exit(EXIT_FAILURE);
	}
	execve(path, &args[0], envp);
	perror("execve error\n");
	//free(path);
	//ft_free_double_pointer(args);
	exit(EXIT_FAILURE);
}

//Hacer función get_path para obtener la ruta del comando a ejecutar
char	*get_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*path;

	path = NULL;
	if (!cmd || cmd[0] == 0)
		return (NULL);
	if (cmd[0] == '/')
		return (ft_strdup(cmd));
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	all_paths = ft_split(*envp + 5, ':');
	if (!all_paths)
		return (NULL);
	printf("all paths:%s\n", all_paths[0]);
	path = find_cmd_in_path(cmd, all_paths);
	//ft_free_double_pointer(all_paths);
	return (path);
}

// //Hacer una función que encuentre el comando
char	*find_cmd_in_path(char *cmd, char **all_paths)
{
	char	*bar_before_cmd;
	char	*trying_cmd;
	int		i;

	i = 0;
	bar_before_cmd = NULL;
	while(all_paths[i] != NULL)
	{
		bar_before_cmd = ft_strjoin(all_paths[i], "/");
		trying_cmd  = ft_strjoin(bar_before_cmd, cmd);
		//free(bar_before_cmd);
		if (access(trying_cmd, F_OK | X_OK) == 0)
			return (trying_cmd);
		free(trying_cmd);
		i++;
	}
	return (NULL);
}
