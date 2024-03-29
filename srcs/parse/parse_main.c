/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:38:11 by grebin            #+#    #+#             */
/*   Updated: 2023/05/12 12:53:29 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	pipe_handler(t_cmd *first, t_cmd *second)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (prints("minishell: pipe error", 2, NULL));
	if (first->output == 1)
		first->output = fd[1];
	else
		close(fd[1]);
	if (second->input == 0)
		second->input = fd[0];
	else
		close(fd[0]);
	return (0);
}

char	**fill_cmd(char *next, int ncmd)
{
	char	**temp;
	char	**cmd;
	int		i;

	i = 0;
	cmd = selectnode(this()->cmds, ncmd)->cmd;
	temp = ft_realloc(cmd, 1);
	while (cmd && cmd[i])
	{
		temp[i] = ft_strdup(cmd[i]);
		if (!temp[i++])
		{
			free_matrix(temp);
			printerror("malloc error", 2);
		}
	}
	temp[i] = ft_strdup(next);
	if (!temp[i])
		printerror("malloc error", 2);
	temp[++i] = NULL;
	free_matrix(cmd);
	selectnode(this()->cmds, ncmd)->cmd = temp;
	return (temp);
}

int	set_cmd(char **arg, int i, int ncmd)
{
	if (!arg[i])
	{
		rmnode(&this()->cmds);
		return (0);
	}
	while (arg && arg[i] && arg[i][0] != '|')
	{
		if ((arg[i][0] == '<' || arg[i][0] == '>'))
			red_handler((arg[i][0] == '<') + (3 * (arg[i][0] == '>')) \
			+ (ft_strlen(arg[i]) == 2), arg[i + 1], ncmd);
		else
			fill_cmd(arg[i], ncmd);
		i += (arg[i][0] == '<' || arg[i][0] == '>') + 1;
	}
	return (i + (arg[i] && arg[i][0] == '|'));
}

void	cmds_split(char **arg)
{
	int		i;
	int		ncmd;

	sigcall()->split = arg;
	ncmd = 0;
	i = 0;
	this()->cmdsindex = 0;
	while (arg && arg[i])
	{
		addtolast(&this()->cmds, createnode(NULL));
		i = set_cmd(arg, i, ncmd);
		this()->cmdsindex++;
		ncmd++;
	}
	while (--ncmd > 0)
		pipe_handler(selectnode(this()->cmds, ncmd - 1), \
		selectnode(this()->cmds, ncmd));
	path_temp();
	if (arg)
		free_matrix(arg);
}
