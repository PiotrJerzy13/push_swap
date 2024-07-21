/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:13:42 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 20:27:14 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char const *s, char delimiter)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimiter)
		{
			word_count++;
			while (s[i] != '\0' && s[i] != delimiter)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (word_count);
}

static char	*extract_word(char const *start, int length)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	cleanup(char **word_array, int word_index)
{
	int	i;

	i = 0;
	while (i < word_index)
	{
		free(word_array[i]);
		word_array[i] = NULL;
		i++;
	}
	free(word_array);
	word_array = NULL;
}

int	parse_words(char **words, char const *s, char delimiter)
{
	int	word_index;
	int	i;
	int	length;
	int	start;

	word_index = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimiter)
		{
			start = i;
			length = 0;
			while (s[i] != '\0' && s[i] != delimiter)
			{
				i++;
				length++;
			}
			words[word_index] = extract_word(s + start, length);
			if (words[word_index] == NULL)
			{
				cleanup(words, word_index);
				return (0);
			}
			word_index++;
		}
		else
		{
			i++;
		}
	}
	return (word_index);
}

char	**ft_split(char const *s, char c)
{
	int		word_count_result;
	char	**words;

	if (s == NULL)
		return (NULL);
	word_count_result = word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (word_count_result + 1));
	if (words == NULL)
		return (NULL);
	words[word_count_result] = NULL;
	if (word_count_result > 0)
	{
		if (parse_words(words, s, c) == 0)
			return (NULL);
	}
	return (words);
}
