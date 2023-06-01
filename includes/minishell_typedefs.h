#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

// Based on the default quantity of envars on the 42 campus iMac;
# define HASH_SIZE 56
# define BUILTIN "echo exit cd export unset pwd env"

typedef struct s_node {
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_hash {
	t_node	*list[HASH_SIZE];
}	t_hash;

typedef struct s_command {
	int		wr_here;
	int		rd_here;
	char	**argv;
}	t_command;

typedef struct s_pipe {
	char		**LEXER_REST;
	char		**REDIRECT_REST;
	char		**envp;
	size_t		id;
	size_t		nbr_sons;
	t_hash		*hash;
	t_command	*command;
}	t_pipe;

typedef struct s_redirect
{
	char	*filename;
	char	*delimiter;
}	t_redirect;

#endif
