/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:30:53 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:08:59 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_calloc.c
 * @brief Implementation of the ft_calloc function.
 *
 * The ft_calloc function allocates memory for an array of nmemb elements of
 * size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element.
 * @return A pointer to the allocated memory, or NULL if the allocation
 * fails or if nmemb or size is 0.
 *
 * The function checks for overflow in the multiplication of nmemb and size.
 * If an overflow is detected, the function returns NULL.
 * If the allocation is successful, the allocated memory is initialized to zero.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	if (total_size / size != nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
