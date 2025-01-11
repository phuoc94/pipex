/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:56:43 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/11 21:07:48 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/includes/libft.h"
# include <sys/wait.h> // waitpid

int		validate_args(int argc, char **argv);
int		create_pipe(int fd[2]);
int		create_fork(void);
void	execute_command(char *cmd, char **envp);
void	handle_child1(int *fd, char **argv, char **envp);
void	handle_child2(int *fd, char **argv, char **envp);
char	*find_cmd_path(char *cmd, char **envp);

void	ft_perror(char *message, char *detail);
int		close_pipe(int fd[2]);
#endif
