/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:56:43 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 19:46:12 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/includes/libft.h"
# include <sys/wait.h> // waitpid

int	validate_args(int argc, char **argv);
int	create_pipe(int fd[2]);
int	create_fork(void);

#endif
