/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:39:01 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/02 16:05:25 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_delim(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtok(char	*str, char *delim)
{
	static char	*cpy_str;
	char		*ret;
	int			i;

	if (str)
		cpy_str = str;
	if (!cpy_str)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = -1;
	while (cpy_str[++i])
	{
		if (!(check_delim(cpy_str[i], delim)))
			ret[i] = cpy_str[i];
		else
		{
			ret[i] = '\0';
			i++;
			return (ret);
		}
	}
	return (ret);
}

// int	count_args(char *str)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\t')
// 		i++;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'')
// 		{
// 			if (check_quotes(str, '\'', &i))
// 				count++;
// 		}
// 		else if (str[i] == '\"')
// 			if (check_quotes(str, '\"', &i))
// 				count++;
// 		i++;
// 	}
// 	return (count);
// }
