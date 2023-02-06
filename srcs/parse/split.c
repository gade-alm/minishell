/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:39:01 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/06 13:31:15 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//Take the string and iterate until it finds a delimiter, then return the word
//before it
char	*copy_args(char *s, char *delim)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len] && !(is_delim(s[len], delim)))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len && !(is_delim(s[i], delim)))
	{
		word[i] = s[i];
		i++;
	}
	if (is_delim(word[i], delim))
		word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *delim)
{
	char	**copy_str;
	int		args_num;
	int		i;

	if (!str || !delim)
		return (NULL);
	args_num = count_args(str);
	copy_str = malloc(sizeof(char *) * (args_num + 1));
	if (!copy_str)
		return (NULL);
	i = 0;
	while (i < args_num)
	{
		while (is_delim(*str, delim))
			str++;
		if (!(is_delim(*str, delim)))
		{
			copy_str[i++] = copy_args(str, delim);
			while (*str && !(is_delim(*str, delim)))
				str++;
		}
	}
	copy_str[i] = NULL;
	return (copy_str);
}
