/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:17:29 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:00:54 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Trims the characters from the beginning and end of a string.
 *
 * This function allocates (with malloc(3)) and returns a copy of the string 's1'
 * with the characters specified in 'set' removed from the beginning and the end
 * of the string.
 *
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	str_len;

	start = 0;
	str_len = ft_strlen(s1);
	end = str_len;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	ptr = malloc((end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], end - start + 1);
	return (ptr);
}
