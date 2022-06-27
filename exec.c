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
	char	*path_val;
	char	*envp_save;

	if (!envp)
		return (NULL);
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	envp_save = envp[i];
	envp[i] = ft_strjoin(envp[i], ":.");
	path_val = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	path = ft_split(path_val, ':');
	free(envp[i]);
	envp[i] = envp_save;
	free(path_val);
	return (path);
}

static char	*make_cmd(char **cmd, char **envp)
{
	char	**path;
	char	*cmd_path;
	char	*path_w_slash;
	int		ret;
	int		i;

	i = 0;
	path = get_path(envp);
	if (!path)
		return (NULL);
	ret = -1;
	while (path[i])
	{
		path_w_slash = ft_strjoin(path[i++], "/");
		cmd_path = ft_strjoin(path_w_slash, cmd[0]);
		free(path_w_slash);
		ret = access(cmd_path, X_OK);
		if (ret == 0)
			break ;
		free(cmd_path);
	}
	ft_free_ptr_array((void **)path);
	if (ret == -1)
		return (NULL);
	return (cmd_path);
}

void	ft_child_process(t_cmd *cmd, int p[2], char **envp)
{
	char	*cmd_path;

	if (dup2(cmd->fd1, STDIN_FILENO) == -1)
		ft_error(NULL, cmd);
	if (dup2(p[1], STDOUT_FILENO) == -1)
		ft_error(NULL, cmd);
	close(p[0]);
	close(cmd->fd1);
	cmd_path = make_cmd(cmd->cmd1, envp);
	if (execve(cmd_path, cmd->cmd1, envp) == -1)
	{
		ft_error(NULL, cmd);
	}
}

int	ft_parent_process(t_cmd *cmd, int p[2], char **envp, pid_t child)
{
	int		status;
	char	*cmd_path;

	waitpid(child, &status, 0);
	if (dup2(cmd->fd2, STDOUT_FILENO) == -1)
		ft_error(NULL, cmd);
	if (dup2(p[0], STDIN_FILENO) == -1)
		ft_error(NULL, cmd);
	close(p[1]);
	close(cmd->fd2);
	cmd_path = make_cmd(cmd->cmd2, envp);
	if (execve(cmd_path, cmd->cmd2, envp) == -1)
	{
		ft_error(NULL, cmd);
	}
	return (0);
}
