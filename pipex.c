/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:09:49 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/18 19:54:15 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static t_cmd	*parse(char *argv)
{
	t_cmd	*cmd;
	char	**cmd_split;

	cmd = (t_cmd *) malloc(sizeof(t_cmd));
	if (!cmd)
		ft_error(E_MALLOC, NULL, NULL);
	cmd_split = ft_split(argv, ' ');
	cmd->cmd_name = cmd_split[0];
	cmd->cmd_args = cmd_split;
	return (cmd);
}

static void	open_file(char **argv, t_cmd *cmd1, t_cmd *cmd2)
{
	cmd1->fd = open(argv[1], O_RDONLY);
	cmd2->fd = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (cmd1->fd == -1 || cmd2->fd == -1)
		ft_error(NULL, cmd1, cmd2);
}

void	ft_error(char *err, t_cmd *cmd1, t_cmd *cmd2)
{
	if (err)
	{
		write(2, err, ft_strlen(err));
		write(2, "\n", 1);
	}
	else
		perror("\e[31mERROR\e[0m");
	ft_free(cmd1, cmd2);
	exit(EXIT_FAILURE);
}

void ft_free(t_cmd *cmd1, t_cmd *cmd2)
{
	int	i;

	if (cmd1)
	{
		i = 0;
		while (cmd1->cmd_args[i])
			free(cmd1->cmd_args[i++]);
		free(cmd1->cmd_args);
		free(cmd1);
	}
	if (cmd2)
	{
		i = 0;
		while (cmd2->cmd_args[i])
			free(cmd2->cmd_args[i++]);
		free(cmd2->cmd_args);
		free(cmd2);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	int		p[2];
	pid_t	child;

	cmd1 = NULL;
	cmd2 = NULL;
	if (argc != 5)
		ft_error(E_ARG, NULL, NULL);
	else
	{
		cmd1 = parse(argv[2]);
		cmd2 = parse(argv[3]);
		open_file(argv, cmd1, cmd2);
		pipe(p);
		child = fork();
		if (child < 0)
			ft_error(NULL, cmd1, cmd2);
		else if (!child)
			ft_child_process(cmd1, p, envp);
		else
			ft_parent_process(cmd2, p, envp, child);
	}
	ft_free(cmd1, cmd2);
	return (0);
}
