#include "../../includes/minishell.h"

static int	expand_and_validate(char *file, t_hash *hash)
{
	char	*temp;

	temp = expand_vars(file, hash);
	if (temp == file)
	{
		if (access(file, R_OK) == -1)
		{
			perror(ERR_READING);
			return (TRUE);
		}
	}
	else if (access(temp, R_OK) == -1)
	{
		perror(ERR_READING);
		free(temp);
		return (TRUE);
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
	if (access(file, R_OK) == -1)
	{
		perror(ERR_READING);
		return (TRUE);
	}
	return (FALSE);
}

int	reading_invalid(char *file, t_hash *hash)
{
	if (!ft_strchr(file, '\'') && !ft_strchr(file, '\"'))
		return (expand_and_validate(file, hash));
	else if (ft_strchr(file, '\"'))
		return (rm_double_and_validate(file, hash));
	else
		return (rm_single_and_validate(file));
}
