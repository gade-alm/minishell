/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:39:40 by gade-alm          #+#    #+#             */
/*   Updated: 2023/05/08 12:46:32 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/executor.h"

void	heredocs_ctrl_d(char *temp, char *delim)
{
	(void)delim;
	if (temp)
		return ;
	if (sigcall()->value[1] != -1)
		close (sigcall()->value[1]);
	printf("minishell: warning: here-document delimited by end-of-file \
	(wanted %s)\n", delim);
	rl_clear_history();
	free (temp);
	child_clean(this()->cmds->next);
	exit(this()->status);
}

void	sig_handler(int signal)
{
	if (signal == SIGQUIT)
		printf("\b\b  \b\b");
	if (signal == SIGINT)
	{
		this()->status = 130;
		write (1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}
