/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:10 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/02 11:59:08 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_quotes(char *str, char c, int *i)
{
	int	cpy;

	if (!str[*i + 1])
		return (0);
	cpy = *i + 1;
	while (str[cpy])
	{
		printf("CHAR %c\n", c);
		if (c == '\"')
		{
			while (str[cpy] != c)
				cpy++;
			if (str[cpy + 1] != ' ')
				cpy++;
		}
		if (str[cpy] == c)
			*i = cpy;
		cpy++;
		return (1);
	}
	*i = cpy;
	printf("%i\n", *i);
	return (0);
}
