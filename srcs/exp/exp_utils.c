/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:13:38 by gabriel           #+#    #+#             */
/*   Updated: 2023/03/12 19:34:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*ft_strcpysize(char *dest, char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] && !isspace(str[i]))
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
