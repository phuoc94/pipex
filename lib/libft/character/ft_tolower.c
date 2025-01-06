/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:39 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:50:24 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @brief Converts an uppercase letter to its lowercase equivalent.
 *
 * This function takes an integer representing a character as input.
 * If the character is an uppercase letter ('A' to 'Z'), it converts it
 * to the corresponding lowercase letter ('a' to 'z'). If the character
 * is not an uppercase letter, it returns the character unchanged.
 *
 * @param c The character to be converted.
 * @return The lowercase equivalent of the character if it is an
 *         uppercase letter, otherwise returns the character unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
