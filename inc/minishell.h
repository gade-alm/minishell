/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:53:03 by gabriel           #+#    #+#             */
/*   Updated: 2023/02/19 11:50:22 by gabriel          ###   ########.fr       */
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
int		char_delim(char *str, int i, char *delim);
char	*ft_word(const char *s, int len);
char	**ft_split(char *str);
int		check_single_quote(char *str);
int		check_double_quote(char *str);
int		check_string(char *str);
int		check_pipe(char *str);
int		token_helper(char *str, char c, int i);
int		token_len(char *str);

#endif
