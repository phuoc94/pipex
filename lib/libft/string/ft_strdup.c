/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:49:00 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:14:47 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_strdup.c
 * @brief Duplicates a string.
 *
 * This function allocates sufficient memory for a copy of the string s,
 * does the copy, and returns a pointer to it. The memory allocated for
 * the new string should be freed by the caller when it is no longer
 * needed.
 *
 * @param s The string to be duplicated.
 * @return A pointer to the newly allocated string, or NULL if memory
 * allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	strlen;
	size_t	i;

	strlen = ft_strlen(s);
	ptr = malloc((strlen + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= strlen)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}
