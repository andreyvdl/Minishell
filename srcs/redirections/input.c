#include "../../includes/minishell.h"

static int	is_directory(char *filename)
{
	struct stat	struct_foda_stat;

	struct_foda_stat = (struct stat){0};
	stat(filename, &struct_foda_stat);
	if (S_ISDIR(struct_foda_stat.st_mode))
		return (TRUE);
	return (FALSE);
}

static int	open_check(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		perror(ERR_READING);
		return (REDI_ERR);
	}
	else if (is_directory(filename) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_INPUT_DIR, strerror(21));
		return (REDI_ERR);
	}
}

int	redirect_input(char *filename, t_command *son, size_t id)
{
	char	*temp;
	int		file_des;

	temp = remove_quotes_and_expand(filename);
	if (open_check(temp) == REDI_ERR)
	{
		if (temp != filename)
			free(temp);
		return (REDI_ERR);
	}
	file_des = open(temp, O_RDONLY);
	if (temp != filename)
		free(temp);
	
	return (REDI_OK);
}
