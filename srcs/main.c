/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/02/03 16:00:12 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int ac, char **av)
{
	char	*str;

	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("$>>:");
		if (str && *str)
			add_history(str);
		printf("%i\n", count_args(str));
		if (ft_strcmp(str, "exit"))
		{
			free (str);
			return (0);
		}
	}
	return (0);
}
