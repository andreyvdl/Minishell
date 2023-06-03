#include "../../includes/minishell.h"

void	is_directory(char *path)
{
	struct stat	file_stat;

	file_stat = (struct stat){0};
	if (stat(path, &file_stat) == -1)
	{
		free_son();
		perror(ERR_STAT);
		exit(EXEC_WENT_WRONG);
	}
	if (S_ISDIR(file_stat.st_mode))
	{
		free_son();
		free(path);
		ft_printf_fd(STDERR_FILENO, ERR_EXEC_DIR, strerror(FT_EISDIR));
		exit(EXEC_WENT_WRONG);
	}
}
