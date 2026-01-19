/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:50:37 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/20 15:50:37 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_copy(char const *s, char c)
{
	int		letters;
	char	*word;
	int		i;

	letters = 0;
	while (s[letters] && s[letters] != c)
		letters++;
	word = malloc(sizeof(char) * (letters + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < letters)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**split_clear(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**split;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		while (*s && *s == c)
			s++;
		split[i] = word_copy(s, c);
		if (!split[i])
			return (split_clear(split, i - 1));
		while (*s && *s != c)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}

/* 
#include<stdio.h>
int main(void)
{
	char string[] = "     d dfsafd    777 $. ";
	printf("Words: %d\n", count_words(string, ' '));

	printf("-------RESULTS FROM FT_SPLIT---------\n");

	char **split = ft_split(string, ' ');
	int i = 0;
	while (i < count_words(string, ' '))
	{
		printf("Word %d : %s\n", i, split[i]);
		i++;
	}
	return (0);
} */