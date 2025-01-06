/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:01:03 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_substr - Allocates and returns a substring from the string 's'.
 * @s: The string from which to create the substring.
 * @start: The start index of the substring in the string 's'.
 * @len: The maximum length of the substring.
 *
 * Return: The substring. NULL if the allocation fails.
 *
 * Description: This function creates a substring from the string 's',
 * starting at index 'start' and of maximum size 'len'. If 'start' is
 * greater than or equal to the length of 's', an empty string is returned.
 * If the length of the substring exceeds the length of 's' from 'start',
 * the substring will be truncated to fit within the bounds of 's'.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub_s = malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	ft_strlcpy(sub_s, &s[start], len + 1);
	return (sub_s);
}
