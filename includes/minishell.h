#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./minishell_typedefs.h"
#include "../libs/libft/includes/libft_structs.h"
#include "../libs/libft/includes/libft_defines.h"
#include "../libs/libft/includes/libft.h"


unsigned int	hash_code(char *key);
t_node	*create_node(char *key, char *value);


#endif // minishell.h
