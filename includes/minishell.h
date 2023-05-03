#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./minishell_typedefs.h"
#include "../libs/libft/includes/libft.h"

// int return
int		cd(char *str);
int		intersections(char *str, char inter);
int		built_ins(char *input, t_hash *hash, char actions);

//void return
void	env(t_hash *hash);
void	pwd(char *str, t_hash *hash);
void	echo(char *str, t_hash *hash);
void	unset(char *str, t_hash *hash);
void	export(char *str, t_hash *hash);
void	parser(char *str, t_hash *hash);
void	builtins(char *input, t_hash *hash);
void	insert_node(t_hash *hash, char *key, char *value);
void	inside_quote_copy(char **str, char **new, char quote);
void	inside_quote_counter(char **str, size_t *counter, char quote);
void	copy_with_expansions(char *str, char *new, t_hash *hash);

// char retunr
char	*separator(char *str);
char	*search(t_hash *hash, char *key);
char	*expand_vars(char *str, t_hash *hash);

// t_node return
t_node	*create_node(char *key, char *value);

// new functions, analyze they before putting in the right place
void	easy_splitter(char *str);
int	unclosed_quotes_case(char **pipeline, char quote);
int pipe_case(char **splited_pline);
int	read_from_case(char **splited_pline);
int	write_to_case(char **splited_pline);

#endif // minishell.h
