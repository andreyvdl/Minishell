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

/* void	printer(char *search, char **input)
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
} */

static void	set_up_hash(t_hash *hash, char **env)
{
	int		i;
	char	*token;

	insert_node(hash, "?", "0");
	i = 0;
	while (env[i])
	{
		token = env_collect(env[i]);
		insert_node(hash, token, &env[i][ft_strlen(env[i]) + 1]);
		i++;
	}
}

void	command(char *input, char **env, t_hash *hash)
{
	char	*pipeline;

	if (input == NULL)
		free_all_and_exit(hash);
	add_to_history(input);
	pipeline = ft_strtrim(input, "\n\v\t\r\f ");
	free(input);
	input = separator(pipeline);
	if (parser(input, hash))
	{
		free(input);
		return ;
	}
	// tokenizer(input, hash);
	// token_and_execution(input, hash);
}

int	main(int argc, char **argv, char **envp)
{
	t_hash	*hash;
	char	*input;

	(void)argc;
	(void)argv;
	hash = (t_hash *)ft_calloc(sizeof(t_hash), 1);
	set_up_hash(hash, envp);
	while (TRUE)
	{
		input = readline("Minishell > ");
		if (input && *input == '\0')
		{
			free(input);
			continue ;
		}
		command(input, envp, hash);
	}
	return (0);
}
