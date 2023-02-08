/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:39:01 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/08 16:37:51 by gade-alm         ###   ########.fr       */
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
	int		delimited;

	len = -1;
	if (!is_delim(s[0], delim))
		while (s[++len] && !(is_delim(s[len], delim)))
			delimited = 0;
	else
		while (s[++len] && is_delim(s[len], delim))
			delimited = 1;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = -1;
	if (delimited == 1)
		while (s[++i] && (is_delim(s[i], delim) && !(is_space(s[len]))))
			word[i] = s[i];
	else
		while (s[++i] && (!is_delim(s[i], delim) && !(is_space(s[len]))))
			word[i] = s[i];
	word[i] = '\0';
	printf("%s\n", word);
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
	i = -1;
	while (++i < args_num)
	{
		while (is_delim(*str, delim))
		{
			copy_str[i] = copy_args(str, delim);
			str++;
		}
		if (!(is_delim(*str, delim)))
		{
			copy_str[i] = copy_args(str, delim);
			while (*str && !(is_delim(*str, delim)))
				str++;
		}
	}
	copy_str[i] = NULL;
	return (copy_str);
}
