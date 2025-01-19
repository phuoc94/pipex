/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:27:36 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:41:12 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_nbr(long nb, int fd)
{
	int	len;
	int	result;

	result = 0;
	len = 0;
	if (nb < 0)
	{
		result = ft_print_char('-', fd);
		if (result == -1)
			return (result);
		len += result;
		nb = -nb;
	}
	if (nb >= 10)
	{
		result = ft_print_nbr(nb / 10, fd);
		if (result == -1)
			return (result);
		len += result;
	}
	result = ft_print_char('0' + (nb % 10), fd);
	if (result == -1)
		return (result);
	len += result;
	return (len);
}
