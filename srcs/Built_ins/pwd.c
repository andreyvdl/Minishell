#include "../../includes/minishell.h"

void	ft_pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror(ERR_PWD_PERROR);
		free_son();
		close_std();
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(cwd) > FT_PATHMAX)
	{
		ft_printf_fd(STDERR_FILENO, ERR_PWD_TOO_LONG, cwd, \
		strerror(FT_ENAMETOOLONG));
		free(cwd);
		free_son();
		close_std();
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd(cwd, STDOUT_FILENO);
	free(cwd);
	free_son();
	close_std();
	exit(EXIT_SUCCESS);
}
