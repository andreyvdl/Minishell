#include "../includes/minishell.h"

//t_node	*create_node(char *key, char *value)



char	*env_collect(char *str)
{
	while (*str != '=' && *str)
	{
		printf("%c", *str);
		str++;
	}
}

void	command(char *(*read)(const char *), char **env)
{
		int	i;

		i = 0;
		while (env[i])
		{
			create_node(env_collect(env[i]), env_collect(env[i]));
			printf("\n");
			i++;
		}
		char *input = read("minishell:> ");
		printf(input);

}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	while (true)
		command(readline, envp);
	return (0);
}
