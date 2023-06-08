#include "../includes/minishell.h"

t_pipe	g_shell;

static char	*env_collect(char *str)
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

static void	set_up_hash(t_hash *hash, char **env)
{
	int		i;
	char	*token;

	insert_node(hash, STATUS_CODE, FATHER_SUCCESS);
	i = 0;
	while (env[i])
	{
		token = env_collect(env[i]);
		insert_node(hash, token, &env[i][ft_strlen(env[i]) + 1]);
		i++;
	}
}

static void	command(char *input, t_hash *hash)
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
	tokenizer(input, hash);
	pre_executor();
}

int	main(int argc, char **argv, char **envp)
{
	t_hash	*hash;
	char	*input;

	if (argc != 1)
		easter_eggs(argv[1]);
	hash = (t_hash *)ft_calloc(sizeof(t_hash), 1);
	set_up_hash(hash, envp);
	g_shell.hash = hash;
	while (TRUE)
	{
		// set_up_signals(); disable for now
		input = readline(PROMPT);
		if (input && *input == '\0')
		{
			free(input);
			continue ;
		}
		// signal(SIGINT, SIG_IGN); disable for now
		command(input, hash);
	}
	return (0);
}
