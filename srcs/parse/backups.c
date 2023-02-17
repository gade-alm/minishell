// char	*copy_args(char **s, int len)
// {
// 	char	*word;
// 	int		i;

// 	word = malloc(sizeof(char) * len + 1);
// 	i = -1;
// 	if (!word)
// 		return (0);
// 	while (++i < len && **s)
// 	{
// 		word[i] = **s;
// 		(*s)++;
// 	}
// 	word[i] = '\0';
// 	printf("%s\n", word);
// 	return (word);
// }

// int	token_len(char *str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 	{
// 		if (is_space(str[i]))
// 			break ;
// 		if (str[i] == '|')
// 		{
// 			token_helper(str, '|', i);
// 			break ;
// 		}
// 		else if (str[i] == '<' || str[i] == '>')
// 		{
// 			while (str[i] == '<' || str[i] == '>')
// 				i++;
// 			break ;
// 		}
// 		else if (str[i])
// 		{
// 			while (str[i] && !ft_strrchr(" \t|<>", str[i]))
// 			{
// 				if (str[i] == '\"')
// 					token_helper(str, '\"', i);
// 				else if (str[i] == '\'')
// 					token_helper(str, '\'', i);
// 				if (str[i])
// 					i++;
// 			}
// 			break ;
// 		}
// 	}
// 	return (i);
// }



// char	**ft_split(char *str)
// {
// 	int		i;
// 	char	**split;
// 	int		num_args;
// 	int		word_size;

// 	if (!str || !str[0])
// 		return (NULL);
// 	num_args = count_args(str);
// 	split = malloc(sizeof(char *) * (num_args + 1));
// 	if (!split)
// 		return (NULL);
// 	i = -1;
// 	while (++i < num_args)
// 	{
// 		word_size = token_len(str);
// 		split[i] = malloc(sizeof(char) * (word_size + 1));
// 		if (!split[i])
// 			return (NULL);
// 		split[i] = ft_word(str, word_size);
// 		str += word_size;
// 	}
// 	split[i] = NULL;
// 	return (split);
// }
