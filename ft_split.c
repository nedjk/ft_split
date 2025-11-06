#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;

	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;

	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			words++;
		while (str[i] && !is_separator(str[i], charset))
			i++;
	}
	return (words);
}

int	ft_strlen_separator(char *str, char *charset)
{
	int i;

	i = 0;

	while (str[i] && !is_separator(str[i], charset))
		i++;
	return i;

}

char *ft_word(char *str, char *charset)
{
	int word_length;
	char *word;
	int i;

	i = 0;
	word = = malloc(sizeof(char) * (word_length + 1));
	word_length = ft_strlen_separator(str,charset);

	while (i < word_length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return word;
}

char	**ft_split(char *str, char *charset)
{
	char **strings;
	int i;
	int j;

	i = 0;
	j = 0;
	strings = malloc(sizeof(char) * (count_words(str,charset) + 1));

	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			strings[j] = ft_word(str[i], charset);
			i++;
			j++;
		}
		while (str[i] && !is_separator(str[i], charset))
			i++;
	}
	strings[j] = 0;
	return(strings);
}
