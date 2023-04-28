#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./minishell_typedefs.h"
#include "../libs/libft/includes/libft.h"

int	cd(char *str);
void	echo(char *str, t_hash *hash);
void	unset(char *str, t_hash *hash);
void	export(char *str, t_hash *hash);
char	*search(t_hash *hash, char *key);
void	builtins(char *input, t_hash *hash);
int		intersections(char *str, char inter);
t_node	*create_node(char *key, char *value);
void	insert_node(t_hash *hash, char *key, char *value);

#endif // minishell.h
