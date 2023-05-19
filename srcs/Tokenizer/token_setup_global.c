#include "../../includes/minishell.h"

static int	fill_son_orders(t_command *son_struct, char *cmd)
{
	size_t	nbr_args;
	size_t	index;
	size_t	arg_index;

	nbr_args = count_args(cmd); // * o loop eh o mesmo
	if (nbr_args == 0)
		return (TRUE);
	son_struct->argv = (char **)ft_calloc(nbr_args + 1, sizeof(char *));
	copy_args(son_struct->argv, cmd);
	// ! PUT TO COPY ARGS, NORM ERROR
	// arg_index = 0;
	// while (*cmd != '\0')
	// {
	// 	if (*cmd == '<' || *cmd == '>')
	// 		cmd += 2;
	// 	else if (*cmd == -7)
	// 		cmd++;
	// 	else if (*cmd != '<' && *cmd != '>' && *cmd != '\0')
	// 	{
	// 		index = 0;
	// 		while (cmd[index] != '\0' && cmd[index] != -7)
	// 			index++;
	// 		son_struct->argv[arg_index] = ft_substr(cmd, 0, index);
	// 		arg_index++;
	// 		cmd += index;
	// 	}
	// }
	return (TRUE);
}

int	set_up_global(char **cmds, size_t nbr_cmds, t_hash *hash)
{
	size_t	counter;

	g_shell.command = (t_command *)ft_calloc(nbr_cmds + 1, sizeof(t_command));
	counter = 0;
	while (counter < nbr_cmds)
	{
		if (fill_son_orders(g_shell.command[counter], *cmds) == FALSE)
		{
			free_sons_orders(counter);
			return (FALSE);
		}
		counter++;
		cmds++;
	}
	g_shell.id = 0;
	g_shell.nbr_sons = nbr_cmds;
	g_shell.envp = hash_to_matrix(hash);
}
/*
* later we think on how to give free to all of this;
*/
