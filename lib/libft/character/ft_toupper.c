/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:33:29 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:51:32 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_toupper.c
 * @brief Converts a lowercase letter to uppercase.
 *
 * This function takes an integer representing a character as input.
 * If the character is a lowercase letter ('a' to 'z'), it converts it to the
 * corresponding uppercase letter.
 * If the character is not a lowercase letter,
 * it returns the character unchanged.
 *
 * @param c The character to be converted.
 * @return The uppercase equivalent of the character if it is a lowercase
 * letter; otherwise, the character itself.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
