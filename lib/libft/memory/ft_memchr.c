/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:18 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:13:04 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_memchr.c
 * @brief Implementation of the ft_memchr function.
 *
 * This function searches for the first occurrence of the character c (an
 * unsigned char) in the first n bytes of the memory area pointed to by s.
 *
 * @param s Pointer to the memory area to be searched.
 * @param c Character to be located. It is passed as an int, but it is
 * internally converted to an unsigned char.
 * @param n Number of bytes to be analyzed.
 * @return A pointer to the first occurrence of the character c in the memory
 * area, or NULL if the character is not found within the given range.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
