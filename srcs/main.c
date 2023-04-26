#include "../includes/minishell.h"

void	command(char *(*read)(const char *))
{
		char *input = read("minishell:> ");
		if (ft_strcmp(input, "ls") == 0)
			printf("%s\n", input);
		free(input);
}

int	main(int argc, char **argv, char **envp)
{
	(void)envp;
	(void)argc;
	(void)argv;

	while (true)
		command(readline);
	return (0);
}
