/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:38 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:00:46 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strrchr - Locate the last occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to be located
 *
 * This function searches for the last occurrence of the character @c
 * in the string pointed to by @s. The terminating null byte is considered
 * part of the string, so if @c is '\0', the function returns a pointer to
 * the terminator.
 *
 * Return: A pointer to the last occurrence of the character @c in the string
 *         @s, or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + len));
	while (len > 0)
	{
		len--;
		if (s[len] == (char)c)
			return ((char *)&s[len]);
	}
	return (NULL);
}
