#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;

<<<<<<< HEAD
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
	(void)argc;
	(void)argv;
	return (0);
=======
int main() {
    printf("%i", hash_code("anderson"));
>>>>>>> 44e1fa67e4d7d6db897c9978ac0782e9da462db9
}
