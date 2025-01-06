/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:27 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:21:15 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_strchr.c
 * @brief Locate character in string.
 *
 * This function locates the first occurrence of the character `c` (converted
 * to a char) in the string pointed to by `s`. The terminating null character
 * is considered to be part of the string; therefore if `c` is `\0`, the
 * function locates the terminating `\0`.
 *
 * @param s The string to be scanned.
 * @param c The character to be searched in the string.
 * @return A pointer to the first occurrence of the character `c` in the
 *         string `s`, or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	return ((char *)ft_memchr(s, c, len + 1));
}
