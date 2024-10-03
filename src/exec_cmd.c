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

void execute_command(char *cmd)
{
    char **args;
    args = ft_split(cmd, ' ');  // Divide el comando en sus argumentos
    execve(args[0], args, NULL);
    perror("execve error");
    exit(EXIT_FAILURE);
}

/*
Hacer función get_path para obtener la ruta del comando a ejecutar
*/

/*
Hacer una función que encuentre el comando
*/
