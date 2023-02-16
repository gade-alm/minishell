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

// char	**ft_split(char **split, char *str, int count)
// {
// 	int		tok_len;
// 	char	*token;

// 	token = NULL;
// 	while (is_space(*str))
// 		str++;
// 	tok_len = token_len(str);
// 	if (tok_len > 0)
// 		token = malloc(sizeof(char) * (tok_len + 1));
// 	if (token)
// 	{
// 		ft_split(split, str + tok_len, count + 1);
// 		token[tok_len] = '\0';
// 	}
// 	token[tok_len] = str[tok_len];
// 	tok_len--;
// 	if (!split)
// 		split = malloc(sizeof(char *) * (count + 1));
// 	if (!split)
// 		return (NULL);
// 	split[count] = token;
// 	return (split);
// }
