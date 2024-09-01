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

#include "../inc/pipex.h" // Suponiendo que tienes un header file llamado "pipex.h"

int main(int argc, char **argv)
{
    // Comprobación de la cantidad de argumentos
    if (argc != 5)
    {
        fprintf(stderr, "Uso: %s archivo1 comando1 comando2 archivo2\n", argv[0]);
        return (EXIT_FAILURE);
    }

    // Aquí podrías inicializar variables y manejar la lógica para ejecutar los comandos
    // Por ejemplo, podrías necesitar abrir los archivos y crear los pipes

    // Abrir archivo1 (input)
    int infile = open(argv[1], O_RDONLY);
    if (infile < 0)
    {
        perror("Error al abrir archivo de entrada");
        return (EXIT_FAILURE);
    }

    // Abrir archivo2 (output)
    int outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0)
    {
        perror("Error al abrir archivo de salida");
        close(infile); // Cierra infile si outfile falla
        return (EXIT_FAILURE);
    }

    // A partir de aquí, deberías manejar los pipes y los procesos hijos
    // Crea un pipe
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("Error al crear pipe");
        close(infile);
        close(outfile);
        return (EXIT_FAILURE);
    }

    // Aquí podrías hacer fork y luego usar execve para ejecutar comando1 y comando2
    // ...

    // No te olvides de cerrar los descriptores de archivo y esperar a los procesos hijos
    // ...

    // Cerrar los archivos antes de terminar el programa
    close(infile);
    close(outfile);

    return (EXIT_SUCCESS);
}

