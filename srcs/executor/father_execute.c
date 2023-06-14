#include "../../includes/minishell.h"

static int	father_redirect(t_command command)
{
	int	backup;

	backup = STDOUT_FILENO;
	if (command.wr_here > STDOUT_FILENO)
	{
		backup = dup(STDOUT_FILENO);
		dup2(command.wr_here, STDOUT_FILENO);
		close(command.wr_here);
	}
	return (backup);
}

void	father_execute(char **argv)
{
	int	backup;

	if (g_shell.command->wr_here <= -1 || g_shell.command->rd_here <= -1)
	{
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
		return ;
	}
	backup = father_redirect(g_shell.command[0]);
	if (ft_strcmp(*argv, "echo") == 0)
		father_echo(argv);
	else if (ft_strcmp(*argv, "cd") == 0)
		father_cd(argv);
	else if (ft_strcmp(*argv, "export") == 0)
		father_export(argv);
	else if (ft_strcmp(*argv, "env") == 0)
		father_env(argv);
	else if (ft_strcmp(*argv, "pwd") == 0)
		father_pwd();
	else if (ft_strcmp(*argv, "exit") == 0)
		father_exit(argv);
	else if (ft_strcmp(*argv, "unset") == 0)
		father_unset(argv);
	dup2(backup, STDOUT_FILENO);
}
