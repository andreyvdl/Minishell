#include "../../includes/minishell.h"

int	pwd()
{
	char	path[4096];

	if (getcwd(path, sizeof(path)) != NULL)
		printf("%s\n", path);
	else
		perror("pwd");
}
