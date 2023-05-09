#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./minishell_typedefs.h"
# include "../libs/libft/includes/libft.h"

# ifndef ERR_QUOTE
#  define ERR_QUOTE "\033[31mms: close this quote `%c`\n\033[0m"
# endif

# ifndef ERR_UNS_SYNTAX
#  define ERR_UNS_SYNTAX "\033[31mms: unsuported syntax `%s`\n\033[0m"
# endif

# ifndef ERR_EOL_SYNTAX
#  define ERR_EOL_SYNTAX "\033[31mms: syntax error `EOL`\033[0m"
# endif

# ifndef ERR_NEXT_SYNTAX
#  define ERR_NEXT_SYNTAX "\033[31mms: syntax error after `%s`\n\033[0m"
# endif

# ifndef ERR_NOW_SYNTAX
#  define ERR_NOW_SYNTAX "\033[31mms: syntax error `%s`\n\033[0m"
# endif

# ifndef ERR_READING
#  define ERR_READING "\033[31mms: read error\033[0m"
# endif

# ifndef ERR_WRITING
#  define ERR_WRITING "\033[31mms: write error\033[0m"
# endif

// int return
int		cd(char *str);
int		pipe_case(char **splited_pline);
int		parser(char *str, t_hash *hash);
int		write_to_case(char **splited_pline);
int		intersections(char *str, char inter);
int		read_from_case(char **splited_pline);
int		unclosed_quotes_case(char **pipeline, char quote);

//void return
void	env(t_hash *hash);
void	free_hash(t_hash *hash);
void	easy_splitter(char *str);
void	pwd(char *str, t_hash *hash);
void	echo(char *str, t_hash *hash);
void	unset(char *str, t_hash *hash);
void	add_to_history(char *pipeline);
void	export(char *str, t_hash *hash);
void	free_all_and_exit(t_hash *hash);
void	builtins(char *input, t_hash *hash);
void	execute_line(char *line, t_hash *hash);
pid_t	execute_command(char **args, t_hash *hash);
void	insert_node(t_hash *hash, char *key, char *value);
void	inside_quote_copy(char **str, char **new, char quote);
void	copy_with_expansions(char *str, char *new, t_hash *hash);
void	inside_quote_counter(char **str, size_t *counter, char quote);

// char retunr
char	*separator(char *str);
char	*search(t_hash *hash, char *key);
char	*expand_vars(char *str, t_hash *hash);

// t_node return
t_node	*create_node(char *key, char *value);

// new functions, analyze they before putting in the right place
int		redirect_invalid(char **split_pline, t_hash *hash);
int		reading_invalid(char *file, t_hash *hash);
int		writing_invalid(char *file, t_hash *hash);

#endif // minishell.h
