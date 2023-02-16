/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:39:01 by gade-alm          #+#    #+#             */
/*   Updated: 2023/02/16 18:33:40 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_word(const char *s, char c)
{
	char			*word;
	int				i;
	int				len;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *delim)
{
	int		i;
	char	**split;
	int		num_args;
	int		word_size;

	if (!str || !str[0])
		return (NULL);
	num_args = count_args(str);
	split = malloc(sizeof(char *) * (num_args + 1));
	if (!split)
		return (NULL);
	i = -1;
	while (++i < num_args)
	{
		word_size = token_len(str);
		split[i] = malloc(sizeof(char) * (word_size + 1));
		if (!split[i])
			return (NULL);
		split[i] = copy_string(str, *delim);
	}
	split[i] = NULL;
	return (split);
}
