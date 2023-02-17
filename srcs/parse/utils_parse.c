/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:10 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/17 18:28:30 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_space(char str)
{
	return (str == ' ' || str == '\t');
}

int	token_helper(char *str, char c, int i)
{
	if (c == '"' || c == '\'')
		while (str[++i] && str[i] != c)
			;
	else
		while (str[i] && str[i] == c)
			i++;
	return (i + (str[i] == c));
}

int	token_len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (is_space(str[i]))
			break ;
		if (str[i] == '|')
		{
			i += token_helper(str, '|', i);
			break ;
		}
		else if (str[i] == '<' || str[i] == '>')
		{
			while (str[i] == '<' || str[i] == '>')
				i++;
			break ;
		}
		else if (str[i])
		{
			while (str[i] && !ft_strrchr(" \t|<>", str[i]))
			{
				if (str[i] == '\"')
					i = token_helper(str, '\"', i);
				else if (str[i] == '\'')
					i = token_helper(str, '\'', i);
				if (str[i] && !ft_strrchr(" \t|<>", str[i]))
					i++;
			}
			break ;
		}
	}
	return (i);
}

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
			while (str[++i] && str[i] != '\"')
				;
		if (str[i] == '\'')
			while (str[++i] && str[i] != '\'')
				;
		if (str[i])
			i++;
	}
	return (i);
}
