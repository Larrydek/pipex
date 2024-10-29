/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larrydek <larrydek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:36:36 by jde-clee          #+#    #+#             */
/*   Updated: 2024/10/29 19:57:12 by larrydek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
CUENTA LA CANTIDAD DE BYTES A ALMACENAR EN LA DIMENSION DE MÁS AFUERA
-LA CANTIDAD DE STRINGS SEPARADAS, BÁSICAMENTE-
*/
// static int	ft_filas(char *s, char c)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (s[j] != 0)
// 	{
// 		while (s[j] == c)
// 			j++;
// 		if (s[j] != c && s[j] != 0)
// 		{
// 			i++;
// 			while (s[j] != c && s[j] != 0)
// 				j++;
// 		}
// 	}
// 	return (i);
// }

// static void	ft_free(char **matriz, int i)
// {
// 	while (i-- > 0)
// 		free(matriz[i]);
// 	free(matriz);
// }

// static char	**ft_matrtiz(char *s, char **matriz, char c, int i)
// {
// 	int	j;
// 	int	k;

// 	k = 0;
// 	while (s[i])
// 	{
// 		while (*(char *)&s[i] == c)
// 			i++;
// 		j = i;
// 		while (s[i] != 0 && *(char *)&s[i] != c)
// 			i++;
// 		if (i > j)
// 		{
// 			matriz[k] = ft_substr(s, j, (i - j));
// 			if (!matriz[k])
// 			{
// 				ft_free(matriz, k);
// 				return (NULL);
// 			}
// 			k++;
// 		}
// 	}
// 	matriz[k] = 0;
// 	return (matriz);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**matriz;
// 	int		i;

// 	i = 0;
// 	matriz = (char **)malloc((ft_filas((char *)s, c) + 1) * sizeof(char *));
// 	if (!matriz)
// 		return (0);
// 	matriz = ft_matrtiz((char *)s, matriz, c, i);
// 	return (matriz);

size_t	ft_n_strings(char *s, char c)
{
	size_t	i;
	size_t	n_strings;

	i = 0;
	n_strings = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			n_strings++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (n_strings);
}

size_t	ft_n_chars(char *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**final_s;

	i = 0;
	j = -1;
	final_s = malloc(sizeof(char *) * (ft_n_strings(s, c) + 1));
	if (!(final_s))
		return (NULL);
	while (++j < ft_n_strings(s, c))
	{
		while (s[i] == c)
			i++;
		ft_n_chars(s, c, i);
		final_s[j] = ft_substr(s, i, ft_n_chars(s, c, i));
		if (!(final_s[j]))
			return (ft_free_matrix(final_s, j), NULL);
		i = i + ft_n_chars(s, c, i);
	}
	return (final_s[j] = 0, final_s);
}
