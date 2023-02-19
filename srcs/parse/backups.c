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
// 		split = ft_split(split, str + tok_len, count + 1);
// 		token[tok_len] = '\0';
// 		while (--tok_len >= 0)
// 			token[tok_len] = str[tok_len];
// 	}
// 	if (!split)
// 		split = malloc(sizeof(char *) * (count + 1));
// 	if (!split)
// 		return (NULL);
// 	split[count] = token;
// 	return (split);
// }