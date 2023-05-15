#include "../../includes/minishell.h"

static char	**count_and_fill(char *input, size_t *n_cmds)
{
	char	**commands;
	size_t	index;

	count_cmds(input, n_cmds);
	commands = (char **)ft_calloc((*n_cmds) + 1, sizeof(char *));
	index = 0;
	while (index < (*n_cmds))
	{
		commands[index] = extract_cmd(&input);
		index++;
	}
	commands[index] = NULL;
	return (commands);
}

/* Arranja um lugar pra essa função depois */
void	wait_child(pid_t pid, size_t n_cmds)
{
	int		wstatus;
	size_t	count;

	count = 1;
	waitpid(pid, &wstatus, 0);
	while (count < n_cmds)
	{
		wait(NULL);
		count++;
	}
}

void	tokenizer(char *input, t_hash *hash)
{
	char	**commands;
	size_t	n_cmds;
	pid_t	pid;

	n_cmds = 0;
	commands = count_and_fill(input, &n_cmds);
	if (n_cmds > 1)
	// {
	// 	while (*commands)
	// 	{
	// 		pid = set_up_multiple_cmd(commands, hash);
	// 		commands++;
	// 	}
	// 	wait_child(pid, n_cmds);
	// }
	else if (n_cmds == 1 && isbuiltin(*commands))
		// TODO: PAI.
	else
		// working_child(*commands, hash);
	free(commands);
}
	/*
	* os comandos estao em commands cada um em 1 string, todos com aspas, sem expandir e com os redirects;
	todo: leitura/escrita de arquivos do filho.
	todo: checagem de acesso de arquivos.
	todo: resto das bultins.
	todo: status code.
	todo: resumindo abaixo.
	pai: faz o lexer e parseia por aspas e syntax;
		se for 1 comando e for builtin ele executa
		se for 1 comando e nao for builtin o filho executa
	filho: abre arquivos e executa comandos;
		se os comandos forem builtins ele deve retornar o status pro pai
		se os comandos nao forem builtins ele deve executar enquanto o pai espera o retorno
	 */
