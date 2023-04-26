#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

# define HASH_SIZE 400

typedef struct s_node {
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_hash {
	t_node	*list[HASH_SIZE];
}	t_hash;

#endif
