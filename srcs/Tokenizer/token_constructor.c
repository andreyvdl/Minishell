#include "../../includes/minishell.h"

static char	**count_and_fill(char *input, size_t *nbr_cmds)
{
	char	**commands;
	size_t	index;

	count_cmds(input, nbr_cmds);
	commands = (char **)ft_calloc((*nbr_cmds) + 1, sizeof(char *));
	index = 0;
	while (index < (*nbr_cmds))
	{
		commands[index] = extract_cmd(&input);
		index++;
	}
	commands[index] = NULL;
	return (commands);
}

void	tokenizer(char *input, t_hash *hash)
{
	char	**commands;
	size_t	nbr_cmd;

	nbr_cmd = 0;
	commands = count_and_fill(input, &nbr_cmd);
	free(input);
	// ! WIP DO NOT DELETE: set_up_global(commands, nbr_cmd, hash);
	ft_free_matrix(commands);
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
