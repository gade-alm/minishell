/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:44:03 by gade-alm          #+#    #+#             */
/*   Updated: 2023/03/13 18:24:46 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	handle_commands(char *str, t_args *args)
{
	char	**split;
	int		i;
	int		j;

	j = -1;
	i = -1;
	split = ft_split(str);
	while (split[++i])
	{
		while (split[++j])
			if (split[i][j] == '$')
				expand_var(split[j], args);
	}
	return (1);
}
