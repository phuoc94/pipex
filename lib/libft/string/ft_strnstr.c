/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:35 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:14:02 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string `little`
 *        in the string `big`, where not more than `len` characters are
 *        searched.
 *
 * @param big The larger string in which to search.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search.
 * @return A pointer to the first occurrence of `little` in `big`, or NULL if
 *         `little` is not found within the first `len` characters of `big`.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!big && len == 0)
		return (NULL);
	i = 0;
	little_len = ft_strlen(little);
	if (little_len <= 0)
		return ((char *)big);
	while (big[i] && (i + little_len <= len))
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(&big[i], little, little_len) == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
