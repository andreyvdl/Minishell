#include "../includes/minishell.h"

void	builtins(char *input, t_hash *hash)
{
	while ((*input == ' ' || *input == '\t'))
		input++;
	if (ft_strncmp(input, "echo ", ft_strlen("echo ")) == 0)
		echo(input, hash);
	else if (ft_strncmp(input, "cd ", ft_strlen("cd ")) == 0)
		cd(input);
	else if (ft_strcmp(input, "pwd") == 0)
		pwd(input, hash);
	else if (ft_strncmp(input, "export ", ft_strlen("export ")) == 0)
		export(input, hash);
	else if (ft_strncmp(input, "unset ", ft_strlen("unset ")) == 0)
		unset(input, hash);
	else if (ft_strncmp(input, "env ", ft_strlen("env ")) == 0)
		env(hash);
	else if (ft_strncmp(input, "exit ", ft_strlen("exit ")) == 0)
		ft_putstr("exit\n");
	else
		return ((void)ft_printf("minishell: command not found: %s\n", input));
}
