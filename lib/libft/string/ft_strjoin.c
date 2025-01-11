/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:57:13 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/11 20:51:27 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Joins two strings into a new string.
 *
 * This function allocates (with malloc(3)) and returns a new string,
 * which is the result of the concatenation of 's1' and 's2'.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string, or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	ptr = malloc((total_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, total_len + 1);
	return (ptr);
}
