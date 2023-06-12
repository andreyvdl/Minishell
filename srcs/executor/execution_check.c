#include "../../includes/minishell.h"

void	execution_check(char *path)
{
	if (filename_too_big(path) == TRUE)
	{
		ft_printf_fd(STDERR_FILENO, ERR_FILENAME, strerror(FT_ENAMETOOLONG));
		free(path);
		free_son();
		close_std_error();
		exit(EXEC_WENT_WRONG);
	}
	is_directory(path);
	if (access(path, F_OK) == -1)
	{
		ft_printf_fd(STDERR_FILENO, ERR_CMD_NOT_FOUND, path);
		free(path);
		free_son();
		close_std_error();
		exit(CMD_NOT_FOUND);
	}
	else if (access(path, X_OK) == -1)
	{
		free(path);
		free_son();
		perror(ERR_ACCESS);
		close_std_error();
		exit(EXEC_WENT_WRONG);
	}
}
