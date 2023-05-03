#include "../includes/minishell.h"

char	*env_collect(char *str)
{	
	int		i;
	char	*s;

	i = 0;
	s = str;
	while (s[i] != '=' && s[i])
		i++;
	s[i] = '\0';
	return (s);
}

void	printer(char *search, char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_strcmp(search, input[i]) == 0)
		{
			printf("%s", input[i]);
			return ;
		}
		printf("%s", input[i]);
		i++;
	}
}

void	command(char *input, char **env, t_hash *hash)
{
	static int		i;
	char			*token;
	char			*pipeline;

	if (i == 0)
	{
		while (env[i])
		{
			token = env_collect(env[i]);
			insert_node(hash, token, &env[i][ft_strlen(env[i]) + 1]);
			i++;
		}
		insert_node(hash, "?", "0");
	}
	if (input == NULL)
	{
		// free em tudo q tem q dar free
		ft_putstr("exit\n");
		exit(0);
	}
	pipeline = ft_strtrim(input, "\n\v\t\r\f ");
	free(input);
	parser(pipeline, hash);
	//builtins(input, hash);
}

int	main(int argc, char **argv, char **envp)
{
	t_hash	*hash;
	char	*input;

	(void)argc;
	(void)argv;
	hash = (t_hash *)malloc(sizeof(t_hash));

	while (true){
		input = readline("Minishell > ");
		command(input,envp, hash);
	}
	return (0);
}
