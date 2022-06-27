/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:10:10 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/18 19:56:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define E_ARG "bad argument"
# define E_PARSE "command parse failed"

typedef struct s_command
{
	char	**cmd1;
	char	**cmd2;
	int		fd1;
	int		fd2;
}	t_cmd;

void	ft_error(char *err, t_cmd *cmd1);
void	ft_free_ptr_array(void **ptr_array);
void	ft_child_process(t_cmd *cmd, int p[2], char **envp);
int		ft_parent_process(t_cmd *cmd, int p[2], char **envp, pid_t child);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif
