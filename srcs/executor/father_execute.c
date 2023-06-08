#include "../../includes/minishell.h"

void	father_execute(char **argv)
{
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
}
