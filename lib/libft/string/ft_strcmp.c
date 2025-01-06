/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:10:18 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:57:33 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strcmp.c
 * @brief Compares two null-terminated strings lexicographically.
 *
 * This function compares the two strings s1 and s2. It returns an integer
 * less than, equal to, or greater than zero if s1 is found, respectively,
 * to be less than, to match, or be greater than s2.
 *
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
