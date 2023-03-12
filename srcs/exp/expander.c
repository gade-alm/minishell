/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:12:13 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/12 19:35:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*check_env(char *str, int i)
{
	char	*temp;
	int		j;
	char	*ret;

	j = 0;
	while (str[++i] && (str[i] != ' ' || str[i] != '\t'))
		j++;
	i -= j;
	temp = malloc(sizeof(char) * j + 1);
	ft_strcpysize(temp, str, i);
	ret = getenv(temp);
	printf("%s\n", ret);
	return (ret);
}
