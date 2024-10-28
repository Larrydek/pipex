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
	//int	daddy_code;

	if (argc != 5)
		ft_error("Error: structure expected ---> ./pipex infile cmd1 cmd2 outfile\n", 2);
	pipex(argv, envp);
}
