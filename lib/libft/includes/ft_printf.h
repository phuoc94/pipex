/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:12:16 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:40:04 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf_fd(int fd, const char *str, ...);
int	ft_printf(const char *str, ...);
int	ft_print_char(char c, int fd);
int	ft_print_ptr(void *ptr, int fd);
int	ft_print_str(char *s, int fd);
int	print_hex(unsigned long n, int uppercase, int fd);
int	ft_print_nbr(long n, int fd);

#endif