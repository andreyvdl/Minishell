#include "../../includes/minishell.h"

static void	skip_redirect(char **cmd)
{
	(*cmd) += 2;
	while (**cmd == -7)
		(*cmd)++;
	while (**cmd != -7 && **cmd != '\0')
		(*cmd)++;
}

static void	copy_args(char **argv, char *cmd)
{
	size_t	index;
	size_t	arg_index;

	arg_index = 0;
	while (*cmd != '\0')
	{
		if (*cmd == '<' || *cmd == '>')
			skip_redirect(&cmd);
		else if (*cmd == -7)
			cmd++;
		else
		{
			index = 0;
			while (cmd[index] != '\0' && cmd[index] != -7)
				index++;
			argv[arg_index] = ft_substr(cmd, 0, index);
			arg_index++;
			ft_memmove(cmd, cmd + index, ft_strlen(cmd + index));
		}
	}
	argv[arg_index] = NULL;
}

static size_t	count_args(char *cmd)
{
	size_t	nbr_args;

	nbr_args = 0;
	while (*cmd != '\0')
	{
		if (*cmd == '<' || *cmd == '>')
			skip_redirect(&cmd);
		else if (*cmd == -7)
			cmd++;
		else
		{
			nbr_args++;
			while (*cmd != '\0' && *cmd != -7)
				cmd++;
		}
	}
}

int	fill_son_orders(t_command *son_struct, char *cmd)
{
	size_t	nbr_args;

	nbr_args = count_args(cmd);
	if (nbr_args > 0)
	{
		son_struct->argv = (char **)ft_calloc(nbr_args + 1, sizeof(char *));
		copy_args(son_struct->argv, cmd);
	}
	return (TRUE);
}
