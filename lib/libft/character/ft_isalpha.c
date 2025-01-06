/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:22:39 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:32:46 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalpha.c
 * @brief Checks if the given character is an alphabetic letter.
 *
 * This function checks if the input character is an alphabetic letter
 * (either lowercase or uppercase).
 *
 * @param c The character to be checked.
 * @return Non-zero value if the character is an alphabetic letter, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}
