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

	if (!envp || !(*envp))
		ft_error("No such file or directory\n", 2);
	if (!cmd[0])
		ft_error("Command '' not found\n", 127);
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		ft_putstr_fd(cmd, 2);
		ft_error(": command not found\n", 1);
	}
	path = get_path(args[0], envp);
	if (!path)
	{
		ft_putstr_fd(cmd, 2);
		ft_error(": command not found\n", 127);
	}
	execve(path, &args[0], envp);
	ft_putstr_fd(cmd, 2);
	ft_error(": No such file or directory\n", 127);
}

//Hacer función get_path para obtener la ruta del comando a ejecutar
char	*get_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*path;

	path = NULL;
	if (!cmd || cmd[0] == 0)
		return (NULL);
	if (cmd[0] == '/' || !ft_strncmp(cmd, "./", 2))
		return (ft_strdup(cmd));
	if (!envp)
		ft_error("Command not found\n", 2);
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	all_paths = ft_split(*envp + 5, ':');
	if (!all_paths)
		return (NULL);
	path = find_cmd_in_path(cmd, all_paths);
	free(all_paths);
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
		if (access(trying_cmd, F_OK | X_OK) == 0)
			return (trying_cmd);
		free(trying_cmd);
		i++;
	}
	//ft_free_double_pointer(all_paths);
	return (NULL);
}
