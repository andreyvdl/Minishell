#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

# ifndef HASH_SIZE
#  define HASH_SIZE 10
# endif


typedef struct s_node {
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_hash {
	t_node	*list[HASH_SIZE];
}	t_hash;

typedef struct s_command {
	char	*path;
	char	**args;
	int		write_to;
	int		read_from;
}	t_command;

typedef struct s_pipe {
	t_command	**command;
	char		**envp;
}	t_pipe;

#endif
