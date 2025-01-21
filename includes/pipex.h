/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:56:43 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/21 09:07:52 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/includes/libft.h"
# include <errno.h>    // errno
# include <fcntl.h>    // open
# include <stdio.h>    // perror
# include <string.h>   // strerror
# include <sys/wait.h> // waitpid

void		validate_args(int argc, char **argv);
void		create_pipe(int fd[2]);
int			create_fork(void);
void		execute_command(char *cmd, char **envp);
void		handle_child1(int fd[2], char **argv, char **envp);
void		handle_child2(int fd[2], char **argv, char **envp);
char		*find_cmd_path(char *cmd, char **envp);
char		**split_with_quotes(const char *cmd);
void		handle_cmd_not_found(char **args);
void		handle_permission_denied(char *cmd_path, char **args);
void		handle_execve_error(char *cmd_path, char **args);
void		print_pipex_error(char *arg);

const char	*find_quote_end(const char *start, char quote);
const char	*find_token_end(const char *start);
char		*create_token(const char *start, size_t len);

void		ft_perror(char *message, char *detail);
void		close_fd(int fd);
void		close_pipe(int fd[2]);
void		safe_dup2(int old_fd, int new_fd);
#endif
