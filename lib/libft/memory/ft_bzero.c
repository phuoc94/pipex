/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:13 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:33:55 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_bzero - Sets the first n bytes of the memory area pointed to by s to zero.
 * @s: Pointer to the memory area to be zeroed.
 * @n: Number of bytes to be set to zero.
 *
 * This function sets the first n bytes of the memory area pointed to by s to
 * zero (bytes containing '\0'). It is typically used to clear a block of
 * memory.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
