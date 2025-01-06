/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:34:17 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:57:19 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_strclen.c
 * @brief Implementation of the ft_strclen function.
 *
 * This function calculates the length of a string up to a specified character.
 *
 * @param s The input string.
 * @param c The character to stop at.
 * @return The length of the string up to the character c, or
 *         the full length if c is not found.
 */
size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
