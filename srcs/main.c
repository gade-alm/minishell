/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/02/17 18:21:36 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int ac, char **av)
{
	char			*str;
	static t_args	args;

	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("$>>:");
		if (str && *str)
			add_history(str);
		if (str && *str)
			args.cmd = ft_split(NULL, str, 0);
		for (int i = 0; args.cmd[i]; i++)
			printf("%s\n", args.cmd[i]);
		if (ft_strcmp(str, "exit\n"))
		{
			free (str);
			return (0);
		}
	}
	return (0);
}
