/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:03:51 by gade-alm          #+#    #+#             */
/*   Updated: 2023/03/12 19:39:39 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


int	check_single_quote(char *str)
{
	int		i;

	i = -1;
	while (str[++i] && str[i] != '\'')
		;
	if (str[i] == '\'')
	{
		if (!str[i + 1])
		{
			printf("Check Quotes\n");
			return (0);
		}
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		if (str[i] == '\'' && str[i + 1] != ' ')
			return (1);
	}
	printf("Check Quotes\n");
	return (0);
}

int	check_double_quote(char *str)
{
	int		i;

	i = -1;
	while (str[++i] && str[i] != '\"')
		;
	if (str[i] == '"')
	{
		if (!str[i + 1])
		{
			printf("Check Quotes\n");
			return (0);
		}
		i++;
		while (str[i] && str[i] != '"')
			i++;
		if (str[i] == '"' && str[i + 1] != ' ')
			return (1);
	}
	printf("Check Quotes\n");
	return (0);
}

int	check_pipe(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '|')
		;
	if (str[i] == '|')
	{
		i++;
		if (str[i] == '|')
		{
			i++;
			if (str[i] == '|')
			{
				printf("Check Pipes\n");
				return (0);
			}
		}
	}
	return (1);
}

int	check_redirection(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] && (str[i] == '>' || str[i] == '<'))
		{
			i++;
			j = i;
			while (str[j] == '>' || str[j] == '<')
			{
				if (str[j + 1] && str[j + 1] == '|')
				{
					printf("Check Redirections\n");
					return (0);
				}
				j++;
			}
		}
	}
	return (1);
}

int	check_string(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			if (!check_single_quote(str))
				return (0);
		if (str[i] == '\"')
			if (!check_double_quote(str))
				return (0);
		if (str[i] == '|')
			if (!check_pipe(str))
				return (0);
		if (str[i] == '>' || str[i] == '<')
			if (!check_redirection(str))
				return (0);
		if (str[i] == '$')
			check_env(str, i);
	}
	return (1);
}
