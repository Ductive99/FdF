/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:56:19 by esouhail          #+#    #+#             */
/*   Updated: 2025/08/14 20:51:00 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

int		count_words(char const *s, char c);
char	**fill_arr(char **arr, const char *s, char c);
char	*ft_strndup(const char *str, int n);
void	free_split(char **arr, int n);

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	words[word_count] = NULL;
	if (word_count > 0)
	{
		if (!fill_arr(words, s, c))
			return (NULL);
	}
	return (words);
}

char	**fill_arr(char **arr, const char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		if ((s[i] == c || !s[i]) && len > 0)
		{
			arr[j] = ft_strndup(&s[i - len], len);
			if (!arr[j])
				return (free_split(arr, j), NULL);
			j++;
		}
	}
	return (arr);
}

void	free_split(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

char	*ft_strndup(const char *str, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

int	count_words(char const *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	while (*s)
	{
		is_word = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			if (is_word == 0)
			{
				is_word = 1;
				count++;
			}
			s++;
		}
	}
	return (count);
}
/*
int	main(int ac, char **av)
{
	char	**res;
	int		i;

	res = ft_split(av[1], av[ac-1][0]);
	printf("%d\n", count_words(av[1], av[ac-1][0]));
	i = 0;
	for (; res[i]; i++)
		printf(">%s<\n", res[i]);
	printf(">%s<\n", res[i]);
	free(res);
}
*/
