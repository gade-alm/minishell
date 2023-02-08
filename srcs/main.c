/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/02/08 15:15:45 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int ac, char **av)
{
	char	*str;
	t_args	*args;

	args = init_args();
	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("$>>:");
		if (str && *str)
			add_history(str);
		if (str && *str)
			args->cmd = ft_split(str, "<>|'\"");
		// if (args->cmd)
		// 	for (int i = 0; i < count_args(str); i++)
		// 		printf("%s\n", args->cmd[i]);
		if (ft_strcmp(str, "exit\n"))
		{
			free (str);
			return (0);
		}
	}
	return (0);
}
