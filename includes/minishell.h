#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./minishell_typedefs.h"
#include "../libs/libft/includes/libft.h"

int		cd(char *str);
void	env(t_hash *hash);
char	*separator(char *str);
void	pwd(char *str, t_hash *hash);
void	echo(char *str, t_hash *hash);
void	unset(char *str, t_hash *hash);
void	export(char *str, t_hash *hash);
void	parser(char *str, t_hash *hash);
char	*search(t_hash *hash, char *key);
void	builtins(char *input, t_hash *hash);
int		intersections(char *str, char inter);
char	*expand_vars(char *str, t_hash *hash);
t_node	*create_node(char *key, char *value);
void	insert_node(t_hash *hash, char *key, char *value);
void	inside_quote_copy(char **str, char **new, char quote);
void	inside_quote_counter(char **str, size_t *counter, char quote);
void	copy_with_expansions(char *str, char *new, t_hash *hash);
#endif // minishell.h
