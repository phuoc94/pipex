/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:49:11 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:41:19 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isdigit.c
 * @brief Checks if the given character is a digit.
 *
 * This function takes an integer value and checks if it corresponds
 * to an ASCII digit character ('0' to '9').
 *
 * @param c The character to be checked.
 * @return Non-zero value if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
