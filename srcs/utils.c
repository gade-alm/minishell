/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:01:47 by gade-alm          #+#    #+#             */
/*   Updated: 2023/01/30 15:41:33 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while ((s1[++i] && s2[i]) && (s1[i] == s2[i]))
		;
	if (i == ft_strlen(s1))
		return (1);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	len = -1;
	str = (char *)s;
	while (str[++len])
		;
	while (len >= 0)
	{
		if (str[len] == (unsigned char) c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}

int	ft_args_counter(char const *s, char *stop)
{
	int		i;
	int		counter;

	i = -1;
	counter = 0;
	while (s[++i])
	{
		while (strrchr(stop, s[i]))
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != stop && s[i] != '\0')
			i++;
	}
	return (counter);
}

char	**split_args(char **ret , char *str, char stop)
{
	int	i;

	i = -1;
	while (*str )
}
