#include "../../includes/minishell.h"

static int	error_msg(void)
{
	perror(ERR_WRITING);
	return (TRUE);
}

static int	expand_and_validate(char *file, t_hash *hash)
{
	char	*temp;

	temp = expand_vars(file, hash);
	if (temp == file)
	{
		if (access(file, F_OK) == -1)
			return (FALSE);
		else if (access(file, W_OK) == -1)
			return (error_msg());
	}
	else
	{
		if (access(temp, F_OK) == -1)
		{
			free(temp);
			return (FALSE);
		}
		else if (access(temp, W_OK) == -1)
		{
			free(temp);
			return (error_msg());
		}
	}
	return (FALSE);
}

static int	rm_double_and_validate(char *file, t_hash *hash)
{
	char	*temp;

	temp = file;
	while (*temp)
	{
		if (*temp == '\"')
		{
			ft_memmove(temp, temp + 1, ft_strlen(temp));
			continue ;
		}
		temp++;
	}
	return (expand_and_validate(file, hash));
}

static int	rm_single_and_validate(char *file)
{
	char	*temp;

	temp = file;
	while (*temp)
	{
		if (*temp == '\'')
		{
			ft_memmove(temp, temp + 1, ft_strlen(temp));
			continue ;
		}
		temp++;
	}
	if (access(file, F_OK) == -1)
		return (FALSE);
	else if (access(file, W_OK) == -1)
		return (error_msg());
	return (FALSE);
}

int	writing_invalid(char *file, t_hash *hash)
{
	if (ft_strchr(file, '\''))
		return (rm_single_and_validate(file));
	else if (ft_strchr(file, '\"'))
		return (rm_double_and_validate(file, hash));
	else
		return (expand_and_validate(file, hash));
}
