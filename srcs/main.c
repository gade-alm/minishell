/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/13 18:25:08 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int ac, char **av)
{
	char			*str;
	static t_args	args;

	(void)ac;
	(void)av;
	(void)args;
	while (1)
	{
		str = readline("$>>:");
		if (str && *str)
			add_history(str);
		if (str && *str)
			if (check_string(str))
				handle_commands(str, init_args());
		if (ft_strcmp(str, "exit\n"))
		{
			free (str);
			return (0);
		}
	}
	return (0);
}
