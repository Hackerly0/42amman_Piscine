/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:10:00 by hnisirat          #+#    #+#             */
/*   Updated: 2024/07/02 12:50:06 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	word_counter(const char *s, char c)
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
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

char	*cpy(const char *start, int len)
{
	char	*word;
	int		index;

	index = 0;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (index < len)
	{
		word[index] = start[index];
		index++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int			words;
	char		**result;
	int			word_index;
	const char	*word_start;

	word_index = 0;
	if (!s)
		return (NULL);
	words = word_counter(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		word_start = s;
		while (*s && *s != c)
			s++;
		if (s > word_start)
			result[word_index++] = cpy(word_start, s - word_start);
	}
	result[word_index] = NULL;
	return (result);
}
/*
int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("Hello world, welcome to 42!", ' ');
	i = 0;
	if (words)
	{
		while (words[i])
		{
			printf("%s\n", words[i]);
			i++;
		}
	}
	return (0);
}
*/
