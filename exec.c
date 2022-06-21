/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:57:11 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/18 19:59:58 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char **envp)
{
	int		i;
	char	**path;

	if (!envp)
		return (NULL);
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	envp[i] = ft_strjoin(envp[i], ":.");
	path = ft_split(ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5), ':');
	return (path);
}

static int	exec_cmd(t_cmd *cmd, char **envp)
{
	char	**path;
	char	*cmd_path;
	int		ret;
	int		i;

	i = 0;
	path = get_path(envp);
	if (!path)
		return (-1);
	ret = -1;
	while (path[i])
	{
		cmd_path = ft_strjoin(ft_strjoin(path[i++], "/"), cmd->cmd_name);
		ret = access(cmd_path, X_OK);
		if (ret == 0)
			break ;
		free(cmd_path);
	}
	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	if (ret == -1)
		ft_error(NULL, cmd, NULL);
	return (execve(cmd_path, cmd->cmd_args, envp));
}

void	ft_child_process(t_cmd *cmd, int p[2], char **envp)
{
	if (dup2(cmd->fd, STDIN_FILENO) == -1)
		ft_error(NULL, cmd, NULL);
	if (dup2(p[1], STDOUT_FILENO) == -1)
		ft_error(NULL, cmd, NULL);
	close(p[0]);
	close(cmd->fd);
	if (exec_cmd(cmd, envp) == -1)
		ft_error(NULL, cmd, NULL);
	system("leaks pipex");
}

void	ft_parent_process(t_cmd *cmd, int p[2], char **envp, pid_t child)
{
	int	status;

	if (dup2(cmd->fd, STDOUT_FILENO) == -1)
		ft_error(NULL, cmd, NULL);
	if (dup2(p[0], STDIN_FILENO) == -1)
		ft_error(NULL, cmd, NULL);
	close(p[1]);
	close(cmd->fd);
	waitpid(child, &status, 0);
	if (exec_cmd(cmd, envp) == -1)
		ft_error(NULL, cmd, NULL);
	system("leaks pipex");
}
