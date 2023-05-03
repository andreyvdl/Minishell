#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

# define HASH_SIZE 10

typedef struct s_node {
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_hash {
	t_node	*list[HASH_SIZE];
}	t_hash;

typedef	enum
{
	WORD,
	META_CHAR,
	COMMAND,
	PIPE
}	e_token_type;

typedef struct s_tokens
{
	char			*value;
	e_token_type	type;
	int				len;
	struct s_tokens	*next;
}	t_tokens;

#endif
