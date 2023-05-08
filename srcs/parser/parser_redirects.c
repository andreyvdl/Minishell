#include "../../includes/minishell.h"

static int	extra_read_case(char *filename)
{
	char	*temp;

	temp = expand_vars(filename);
	if (access(temp, R_OK) == -1)
	{
		perror(RED"ms:read error: "RESET);
		free(temp);
		return (TRUE);
	}
	return (FALSE);
}

static int	invalid_read_case(char *filename)
{
	char	*temp;

	if (ft_strchr(filename, '\'') != NULL)
	{
		remove_quote(filename);
		if (access(filename, R_OK) == -1)
		{
			perror(RED"ms:read error: "RESET);
			return (TRUE);
		}
	}
	else if (ft_strchr(filename, '\"') != NULL)
	{
		remove_quote(filename);
		temp = expand_vars(filename);
		if (access(temp, R_OK) == -1)
		{
			perror(RED"ms:read error: "RESET);
			free(temp);
			return (TRUE);
		}
	}
	return (extra_read_case(filename));
}

static int	invalid_write_case(*filename)
{
	char	*temp;
	int		fd;

	if (ft_strchr(filename, '\'') != NULL)
	{
		remove_quote(filename);
		fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR & S_IWUSR | S_IRGRP \
		| S_IROTH);
		if (fd == -1)
		{
			perror(RED"ms:write error: "RESET);
			free(temp);
			return (TRUE);
		}
	}
	else if (ft_strchr(filename, '\"') != NULL)
	{
		remove_doubleq(filename);
		temp = expand_vars(filename);
		if (access(temp, W_OK) == -1)
		{
			perror(RED"ms:write error: "RESET);
			free(temp);
			return (TRUE);
		}
	}
	return (FALSE);
}

int	redirect_invalid(char **splited_pline)
{
	while (*splited_pline)
	{
		if (ft_strchr("<", **splited_pline) && !ft_strstr(*splited_pline, "<<"))
		{
			if (invalid_read_case(*(splited_pline + 1)))
				return (TRUE);
		}
		else if (ft_strchr(">", **splited_pline))
		{
			if (invalid_write_case(*(splited_pline + 1)))
				return (TRUE);
		}
		splited_pline++;
	}
	return (FALSE);
}
