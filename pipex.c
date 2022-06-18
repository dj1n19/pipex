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

static t_cmd	*parse(char *argv)
{
	t_cmd	*cmd;
	char	**cmd_split;

	cmd = (t_cmd *) malloc(sizeof(t_cmd));
	if (!cmd)
		ft_error(E_MALLOC);
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
		ft_error(NULL);
}

void	ft_error(char *err)
{
	if (err)
	{
		write(2, err, ft_strlen(err));
		write(2, "\n", 1);
	}
	else
		perror("ERROR");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	int		p[2];
	pid_t	child;

	if (argc != 5)
		ft_error(E_ARG);
	else
	{
		cmd1 = parse(argv[2]);
		cmd2 = parse(argv[3]);
		open_file(argv, cmd1, cmd2);
		pipe(p);
		child = fork();
		if (child < 0)
			ft_error(NULL);
		else if (!child)
			ft_child_process(cmd1, p, envp);
		else
			ft_parent_process(cmd2, p, envp, child);
	}
	return (0);
}
