#include "../includes/minishell.h"

void	builtins(char *input, t_hash *hash)
{
	while ((*input == ' ' || *input == '\t'))
		input++;
	if (ft_strncmp(input, "echo", ft_strlen("echo")) == 0)
		echo(input, hash);
	else if (ft_strncmp(input, "cd", ft_strlen("cd")) == 0)
		ft_putstr("change directory\n");
	else if (ft_strncmp(input, "pwd", ft_strlen("pwd")) == 0)
		ft_putstr("pwd\n");
	else if (ft_strncmp(input, "export", ft_strlen("export")) == 0)
		ft_putstr("export\n");
	else if (ft_strncmp(input, "unset", ft_strlen("unset")) == 0)
		ft_putstr("unset\n");
	else if (ft_strncmp(input, "env", ft_strlen("env")) == 0)
		ft_putstr("env\n");
	else if (ft_strncmp(input, "exit", ft_strlen("exit")) == 0)
		ft_putstr("exit\n");
		//mini_exit(input + 4, hash);
	else
		return ;
}
