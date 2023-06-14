#include "../../includes/minishell.h"

static void	print_vars_export(void)
{
	t_node	*node;
	size_t	looper;

	looper = 0;
	while (looper < HASH_SIZE)
	{
		node = g_shell.hash->list[looper];
		while (node != NULL)
		{
			if (*node->key != '?' && node->value != NULL)
				ft_printf_ln(EXPORT_PRINT_VALUE, node->key, node->value);
			else if (*node->key != '?')
				ft_printf_ln(EXPORT_PRINT_VAR, node->key);
			node = node->next;
		}
		looper++;
	}
	insert_node(g_shell.hash, STATUS_CODE, FATHER_SUCCESS);
}

static void	add_this_to_hash(char *copy, size_t len, int has_value)
{
	copy[len] = '\0';
	if (has_value == TRUE)
		insert_node(g_shell.hash, copy, copy + len + 1);
	else
		insert_node(g_shell.hash, copy, NULL);
}

static int	add_var(char *arg)
{
	char	*copy;
	size_t	len;

	copy = ft_strdup(arg);
	len = 0;
	if (ft_isalpha(copy[len]) == FALSE && copy[len] != '_')
	{
		free(copy);
		return (FALSE);
	}
	while ((ft_isalnum(copy[len]) == TRUE || copy[len] == '_') && \
	copy[len] != '\0')
		len++;
	if (copy[len] != '=' && copy[len] != '\0')
	{
		free(copy);
		return (FALSE);
	}
	else if (copy[len] == '=')
		add_this_to_hash(copy, len, TRUE);
	else
		add_this_to_hash(copy, len, FALSE);
	return (TRUE);
}

static void	add_new_vars(char **argv)
{
	int	printed;

	argv++;
	printed = 0;
	while (*argv != NULL)
	{
		if (add_var(*argv) == FALSE)
			printed = ft_printf_fd(STDERR_FILENO, ERR_EXPORT_INVALID, *argv);
		argv++;
	}
	if (printed != 0)
		insert_node(g_shell.hash, STATUS_CODE, FATHER_FAILURE);
	else
		insert_node(g_shell.hash, STATUS_CODE, FATHER_SUCCESS);
}

void	father_export(char **argv)
{
	if (*(argv + 1) == NULL)
	{
		print_vars_export();
		return ;
	}
	add_new_vars(argv);
}
