/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:57:46 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:57:56 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_striteri - Applies a function to each character of a string.
 * @s: The string to iterate over.
 * @f: The function to apply to each character. The function takes two
 *     arguments: the index of the character in the string and a pointer
 *     to the character itself.
 *
 * This function iterates over each character of the string 's' and applies
 * the function 'f' to each character. The function 'f' is called with the
 * index of the character and a pointer to the character itself.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
