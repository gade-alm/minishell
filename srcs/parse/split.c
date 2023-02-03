/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:39:01 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/03 18:15:03 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	char_delim(char *str, int i, char *delim)
{
	if (ft_strrchr(delim, str[i]))
	{
		while (str[i] && ft_strrchr(delim, str[i]))
			i++;
		return (i);
	}
	while (!ft_strrchr(delim, str[i]))
	{
		if (str[i] == '\"')
			while (str[i] && str[i] != '\"')
				i++;
		if (str[i] == '\'')
			while (str[i] && str[i] != '\'')
				i++;
		if (str[i] && !ft_strrchr(delim, str[i]))
			i++;
	}
	return (i);
}

int	count_args(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '<' || str[i] == '<' || str[i] == '|')
			i = char_delim(str, i, "<>|");
		else if (str[i])
			i = char_delim(str, i, " \t<>|");
		else
			break ;
		count++;
	}
	return (count);
}
