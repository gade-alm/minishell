/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:39:06 by grebin            #+#    #+#             */
/*   Updated: 2023/04/11 12:16:15 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

long	ft_atoi(char *s)
{
	long	n;
	long	sig;
	int		i;

	n = 0;
	i = -1;
	sig = 1;
	while (s[++i] > 8 && s[i] < 13)
		;
	if (s[i] == '-' || s[i] == '+')
	{
		sig = (s[i] != '-') - (s[i] == '-');
		i++;
	}
	while (s[++i] >= '0' && s[i] <= '9')
		n = n * 10 + sig * (s[i++] - '0');
	while (s[i] > 8 && s[i] < 13)
		i++;
	return (n);
}

static int	ft_numdig(int n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (1 + ft_numdig(n / 10));
}

char	*ft_itoa(int n)
{
	char	*num;
	int		num_dig;
	int		i;
	int		signal;

	signal = n;
	num_dig = ft_numdig(n) + 1 + (n < 0);
	num = (char *)malloc(sizeof(char) * num_dig);
	if (!num)
		return (NULL);
	num[num_dig - 1] = '\0';
	i = num_dig - 2;
	while (i > -1)
	{
		num[i] = ((n % 10) * ((n > 0) - (n < 0))) + 48;
		n /= 10;
		i--;
	}
	if (signal < 0)
		num[0] = '-';
	return (num);
}

int	printerror(char *str)
{
	if (*str)
		prints(str, 1);
	if (this()->env)
		free_matrix(this()->env);
	rmlist(&this()->cmds);
	exit (1);
}
