/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:21:30 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/12 13:35:18 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(s);
	words = 0;
	i = 0;
	while (i < str_len)
	{
		while (s[i] == c)
			i++;
		if (i < str_len && s[i] != c)
		{
			words++;
			while (i < str_len && s[i] != c)
				i++;
		}
	}
	return (words);
}

void	free_ft_split(char ***ptr_strs)
{
	char	**strs;
	int		i;

	if (ptr_strs == NULL || *ptr_strs == NULL)
		return ;
	strs = *ptr_strs;
	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	*ptr_strs = NULL;
}

static int	split(char **strs, const char *s, char c, size_t n)
{
	size_t	i;
	size_t	current_word;
	size_t	cwordlen;

	current_word = 0;
	i = 0;
	while (current_word < n)
	{
		while (s[i] == c)
			i++;
		cwordlen = ft_strclen(&s[i], c);
		strs[current_word] = malloc((cwordlen + 1) * sizeof(char));
		if (!strs[current_word])
		{
			free_ft_split(&strs);
			return (0);
		}
		ft_strlcpy(strs[current_word], &s[i], cwordlen + 1);
		i = i + cwordlen;
		current_word++;
	}
	return (1);
}

/**
 * ft_split - Splits a string into an array of strings based on a delimiter.
 * @s: The input string to be split.
 * @c: The delimiter character.
 *
 * This function takes a string `s` and splits it into an array of strings
 * using the delimiter character `c`. The resulting array of strings is
 * dynamically allocated and must be freed by the caller. The last element
 * of the array is set to NULL to mark the end of the array.
 *
 * Return: A pointer to the array of strings,
	or NULL if memory allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	strslen;

	strslen = count_words(s, c);
	strs = malloc((strslen + 1) * (sizeof(char *)));
	if (!strs)
		return (NULL);
	strs[strslen] = 0;
	if (!(split(strs, s, c, strslen)))
		return (NULL);
	return (strs);
}
