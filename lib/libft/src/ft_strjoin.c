/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 04:26:31 by jde-clee          #+#    #+#             */
/*   Updated: 2024/08/19 04:14:18 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len_s1s2;
	char	*str;

	i = 0;
	j = 0;
	len_s1s2 = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len_s1s2 + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}
