/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:39:01 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/04 12:35:13 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


char	*copy_args(char *s, char delim)
{
	char			*word;
	int				i;
	int				len;

	i = 0;
	len = 0;
	while (s[len] && s[len] != delim)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[i] && s[i] != delim)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char delim)
{
	char	**copy_str;
	int		args_num;
	int		i;

	args_num = count_args(str);
	copy_str = malloc(sizeof(char *) * (args_num + 1));
	if (!copy_str)
		return (NULL);
	i = 0;
	while (args_num-- > 0)
	{
		while (is_space(str[++i]))
			;
		if (str[i] != delim && str[i])
		{
			copy_str[i] = copy_args(str, delim);
			i++;
			while (str[i] != delim && str[i])
				i++;
		}
	}
	for (int j = 0; j < i; j++)
		printf("%s\n", copy_str[j]);
	copy_str[i] = NULL;
	return (copy_str);
}
