#include "../../includes/minishell.h"

static char **bins_path()
{
	return (ft_split(search(g_shell.hash, "PATH"), ':'));
}

static char **concat_bar()
{
	char	**bin;
	char	*path;
	int		i;


	bin = bins_path();
	i = 0;
	while (bin && bin[i])
	{
		if (!(bin[i][ft_strlen(bin[i]) - 1] == '/'))
		{
			path = ft_strjoin(bin[i], "/");
			free(bin[i]);
			bin[i] = path;
		}
		i++;
	}
	bin[i] = NULL;
	return (bin);
}

static char	**path_creator(char *command)
{
	char	**bin;
	char	*path;
	int		i;

	bin = concat_bar();
	i = 0;
	while (bin && bin[i])
	{
		path = ft_strjoin(bin[i], command);
		free(bin[i]);
		bin[i]= path;
		i++;
	}
	bin[i] = NULL;
	return (bin);
}

static	void	runtime(char **bins)
{
	pid_t	pid;
	int		executed;
	size_t		i;

	i = 0;
	executed = 0;
	while (bins && *bins)
	{
		if (access((*bins), X_OK) == 0 && !executed)
		{
			executed = 1;
			pid = fork();
			if (pid == 0)
			{
				if (execve((*bins), g_shell.command->argv, g_shell.envp) == -1)
					perror("execvp");
				exit(0);
			}
			else if (pid < 0)
				perror("fork");
			else
			{
				while (i++ < g_shell.nbr_sons)
					wait(NULL);
			}
		}
		bins++;
	}
}

void	executor()
{
	if (isbuiltin(g_shell.command->argv[0]))
		builtins();
	else
	{
		runtime(path_creator(g_shell.command->argv[0]));
		ft_free_matrix((void **)g_shell.command->argv);
	}
}