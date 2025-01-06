/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:34 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:31:37 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

/**
 * @brief Compares up to n characters of the null-terminated strings s1 and s2.
 *
 * This function compares the two strings s1 and s2. It returns an integer less
 * than, equal to, or greater than zero if s1 is found, respectively, to be less
 * than, to match, or be greater than s2. The comparison is done using unsigned
 * characters, so that `\200' is greater than `\0'.
 *
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @param n The maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if s1 (or the
 *         first n bytes thereof) is found, respectively, to be less than, to
 *         match, or be greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
