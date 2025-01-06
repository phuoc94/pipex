/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:23 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:10:00 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_memmove.c
 * @brief Implementation of the ft_memmove function.
 *
 * The ft_memmove function copies n bytes from memory area src to memory area
 * dest. The memory areas may overlap: copying takes place as though the bytes
 * in src are first copied into a temporary array that does not overlap src or
 * dest, and the bytes are then copied from the temporary array to dest.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area (dest).
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;
	int					i;

	if (!dest && !src)
		return (NULL);
	ptrdest = (unsigned char *)dest;
	ptrsrc = (const unsigned char *)src;
	if (ptrdest < ptrsrc)
		ft_memcpy(dest, src, n);
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			ptrdest[i] = ptrsrc[i];
			i--;
		}
	}
	return (dest);
}
