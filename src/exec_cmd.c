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
	char **args;
	char *path;

	args = ft_split(cmd, ' ');  // Divide el comando en sus argumentos

	execve(path, args, envp);
	perror("execve error");
	exit(EXIT_FAILURE);
}


//Hacer función get_path para obtener la ruta del comando a ejecutar
char	*get_path(char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp(&envp, "PATH=", 5))
			return (*envp + 5);
		*envp++;
	}
	return (NULL);
}

//Hacer una función que encuentre el comando
char	*find_cmd_in_path(char *cmd, char **envp)
{

}