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

static t_cmd	*parse(char **argv)
{
	t_cmd	*cmd;
	char	**cmd_split1;
	char	**cmd_split2;

	cmd = (t_cmd *) malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd_split1 = ft_split(argv[2], ' ');
	if (!cmd_split1 || !cmd_split1[0])
	{
		ft_free_ptr_array((void **)cmd_split1);
		free(cmd);
		return (NULL);
	}
	cmd->cmd1 = cmd_split1;
	cmd_split2 = ft_split(argv[3], ' ');
	if (!cmd_split2 || !cmd_split2[0])
	{
		ft_free_ptr_array((void **)cmd_split1);
		ft_free_ptr_array((void **)cmd_split2);
		free(cmd);
		return (NULL);
	}
	cmd->cmd2 = cmd_split2;
	return (cmd);
}

static void	open_file(char **argv, t_cmd *cmd)
{
	cmd->fd1 = open(argv[1], O_RDONLY);
	if (cmd->fd1 < 0)
		ft_error(NULL, cmd);
	cmd->fd2 = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (cmd->fd2 < 0)
	{
		close(cmd->fd1);
		ft_error(NULL, cmd);
	}
}

void	ft_error(char *err, t_cmd *cmd)
{
	if (err)
	{
		write(2, "ERROR: ", 7);
		write(2, err, ft_strlen(err));
		write(2, "\n", 1);
	}
	else
		perror("\e[31mERROR\e[0m");
	if (cmd)
	{
		ft_free_ptr_array((void **)cmd->cmd1);
		ft_free_ptr_array((void **)cmd->cmd2);
		free(cmd);
	}
	exit(EXIT_FAILURE);
}

void ft_free_ptr_array(void **ptr_array) {
	int	i;

	i = 0;
	if (ptr_array)
	{
		while (ptr_array[i])
		{
			free(ptr_array[i]);
			i++;
		}
		free(ptr_array);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	int		p[2];
	pid_t	child;

	cmd = NULL;
	if (argc != 5)
		ft_error(E_ARG, NULL);
	else
	{
		cmd = parse(argv);
		if (!cmd)
			ft_error(E_PARSE, cmd);
		open_file(argv, cmd);
		if (pipe(p))
			ft_error("GNAH", cmd);
		child = fork();
		if (child < 0)
			ft_error(NULL, cmd);
		else if (!child)
			ft_child_process(cmd, p, envp);
		else
			ft_parent_process(cmd, p, envp, child);
	}
	return (0);
}
