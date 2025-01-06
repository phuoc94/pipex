/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:12:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/13 19:01:16 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_ptr(void *ptr);
int	ft_print_str(char *s);
int	print_hex(unsigned long n, int uppercase);
int	ft_print_nbr(long n);

#endif