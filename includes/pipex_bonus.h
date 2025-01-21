/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:56:43 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/21 09:51:40 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../lib/libft/includes/libft.h"
# include <sys/wait.h> // waitpid
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h> // perror
# include <string.h> // strerror

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		prev_fd;
	int		fd[2];
	int		last_pid;
	int		cmd_count;
	bool	here_doc;
	char	*limiter;
}			t_pipex;

void		validate_args(int argc, char **argv);
void		create_pipe(int fd[2]);
int			create_fork(void);
void		execute_command(char *cmd, char **envp);
void		handle_first_child(t_pipex *pipex);
void		handle_middle_child(t_pipex *pipex, int i);
void		handle_last_child(t_pipex *pipex);
char		*find_cmd_path(char *cmd, char **envp);
void		read_here_doc(t_pipex *pipex);
void		print_pipex_error(char *arg);

void		ft_perror(char *message, char *detail);
void		close_fd(int fd);
void		close_pipe(int fd[2]);
void		safe_dup2(int old_fd, int new_fd);
#endif
