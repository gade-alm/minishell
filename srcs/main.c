/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:25 by gabriel           #+#    #+#             */
/*   Updated: 2023/02/19 11:50:55 by gabriel          ###   ########.fr       */
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
		if (check_string(str))
			args.cmd = ft_split(str);
		if (args.cmd)
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
