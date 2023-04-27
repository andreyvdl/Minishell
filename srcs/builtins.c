#include "../includes/minishell.h"


void	builtins(char *input, t_hash *hash)
{
	while ((*input == ' ' || *input == '\t'))
		input++;
	if (ft_strncmp(input, "echo", ft_strlen("echo")) == 0)
		echo(input, hash);
	else if (ft_strncmp(input, "cd", ft_strlen("cd")) == 0)
		printf("change directory\n");
	else if (ft_strncmp(input, "pwd", ft_strlen("pwd")) == 0)
		printf("pwd\n");
	else if (ft_strncmp(input, "export", ft_strlen("export")) == 0)
		printf("export\n");
	else if (ft_strncmp(input, "unset", ft_strlen("unset")) == 0)
		printf("unset\n");
	else if (ft_strncmp(input, "env", ft_strlen("env")) == 0)
		printf("env\n");
	else if (ft_strncmp(input, "exit", ft_strlen("exit")) == 0)
		printf("exit\n");
	else
		return;
}