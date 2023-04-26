#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	*line;

	line = NULL;
	while (true)
	{
		line = readline("mini> ");
		if (line == NULL)
		{
			ft_putstr("exit\n");
			break ;
		}
		else if (*line != '\0')
		{
			printf("Voce escreveu: [%s]\n", line);
			free(line);
		}
	}
	// A gente nao vai usar eles a nao ser que queira fazer easter egg
	
	return (0);
}
