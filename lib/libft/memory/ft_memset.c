/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:25 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:47:06 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_memset.c
 * @brief Implementation of the memset function.
 *
 * This function fills the first n bytes of the memory area pointed to by s
 * with the constant byte c.
 *
 * @param s Pointer to the memory area to be filled.
 * @param c The byte value to be set.
 * @param n The number of bytes to be set to the value.
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
