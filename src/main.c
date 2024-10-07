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
	if (argc != 5)
	{
		ft_putstr_fd("Error: structure expected ---> ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (EXIT_FAILURE);
	}

	pipex(argv, envp);
	return (EXIT_SUCCESS);
}
