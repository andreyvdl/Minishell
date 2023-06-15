#include "../../includes/minishell.h"

void	builtins(char **argv)
{
	if (ft_strcmp(*argv, "echo") == 0)
		ft_echo(argv);
	else if (ft_strcmp(*argv, "cd") == 0)
		ft_cd(argv);
	else if (ft_strcmp(*argv, "export") == 0)
		ft_export(argv);
	else if (ft_strcmp(*argv, "env") == 0)
		ft_env(argv);
	else if (ft_strcmp(*argv, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(*argv, "exit") == 0)
		ft_exit(argv);
	else if (ft_strcmp(*argv, "unset") == 0)
		ft_unset(argv);
}