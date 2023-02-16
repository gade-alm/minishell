/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:03:51 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/16 18:29:26 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*copy_string(char *str, char delim)
{
	int		i;
	char	*dest;

	i = -1;
	dest = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[++i] && str[i] != delim)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
