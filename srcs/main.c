#include "../includes/minishell.h"

//t_node	*create_node(char *key, char *value)

char	*env_collect(char *str)
{	
	char *s;
	
	int i;

	i = 0;
	s = str;

	while (s[i] != '=' && s[i])
		i++;
	s[i] = '\0';
	return (s);
}

void	printer(char *search, char **input)
{
	int i = 0;
	while (input[i])
	{
		if (ft_strcmp(search, input[i]) == 0)
		{
			printf(input[i]);
			return;
		}
		printf(input[i]);
		i++;
	}
}


void	command(char *(*read)(const char *), char **env)
{
		int	i;
		char	*input; 
		t_hash *hash;
		

		i = 0;
		char *token;
		hash = (t_hash *)malloc(sizeof(t_hash));
		
		while (env[i])
		{
			token = env_collect(env[i]);

			insert_node(hash, token, &env[i][ft_strlen(env[i]) + 1]);
			//printf(env[i]);
			i++;
		}
		input = read("minishell:> ");
		printf("%s\n", search(hash, input));
		
		
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	while (true)
		command(readline, envp);
	return (0);
}
