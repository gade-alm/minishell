/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:53:03 by gabriel           #+#    #+#             */
/*   Updated: 2023/02/08 17:58:46 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef struct s_args{
	int		input;
	int		output;
	char	**cmd;
	char	*path;
	char	*next;
}	t_args;

//UTILS AREA
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		is_space(char str);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
t_args	*init_args(void);

//PARSE AREA
int		count_args(char *str);
int		is_delim(char str, char *delim);
char	*copy_args(char *s, char *delim);
char	**ft_split(char *str, char *delim);
int		is_quotes(char *str, int i, char quote);

#endif