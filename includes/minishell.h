#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "./minishell_typedefs.h"
# include "../libs/libft/includes/libft.h"



#ifdef __APPLE__
		#define SYSTEM_TYPE " \033[0;35m\033[0m "
#elif defined(_WIN32)
		#define SYSTEM_TYPE " \033[0;32m\033[0m "
#elif defined(__linux__)
		#define SYSTEM_TYPE " \033[0;36m\033[0m "
#else
		#define SYSTEM_TYPE " \033[0;31m\033[0m "
#endif

# define PROMPT "\n\033[1;34m  Minishell\033[0m\n" SYSTEM_TYPE "\033[1;33m\033[0m "

// # define ERR_FORK "\e[1;5;31mms: forking error\e[0m"
# define ERR_QUOTE "\e[1;5;31mms: close this quote \e[1m`%c`\n\e[0m"
# define ERR_READING "\e[1;5;31mms: read error\e[0m"
# define ERR_WRITING "\e[1;5;31mms: write error\e[0m"
# define ERR_HEREDOC "\e[1;5;31mms: heredoc error...\n\e[0m"
# define WAR_HEREDOC "\e[1;33mms: finish with EOF, expected `%s`\n\e[0m"
# define HEREDOC_PATH "/tmp/.heredoc"
# define ERR_INPUT_DIR "\e[1;5;31mms: read error: %s\n\e[0m"
# define HEREDOC_PROMPT "here-document> "
# define ERR_UNS_SYNTAX "\e[1;5;31mms: unsuported syntax \e[1m`%s`\n\e[0m"
# define ERR_EOL_SYNTAX "\e[1;5;31mms: syntax error \e[1m`EOL`\e[0m"
# define ERR_NOW_SYNTAX "\e[1;5;31mms: syntax error \e[1m`%s`\n\e[0m"
# define ERR_NEXT_SYNTAX "\e[1;5;31mms: syntax error after \e[1m`%s`\n\e[0m"

# define REDI_OK 0
# define REDI_ERR 1
# define SIGNAL_INT 130
# define REDI_SIGNAL -1

# define TRUNC 01101
# define APPEND 02101
# define HEREDOC 01102
# define PERM_CREATE 0644

// ! GLOBAL: NEVER DIRECTELY INCREMENT ANY POINTER INSIDE THE STRUCT;
extern t_pipe	g_shell;

// int return
int		cd();
int		isbuiltin(char *check);
int		parser(char *str, t_hash *hash);
int		pipe_case(char **splited_pline);
int		write_to_case(char **splited_pline);
int		intersections(char *str, char inter);
int		read_from_case(char **splited_pline);
int		heredoc(char *limiter, t_command *son, size_t id);
int		fill_son_orders(t_command *son_struct, char *cmd);
int		unclosed_quotes_case(char **pipeline, char quote);
int		redirection(char **str, t_command *son, size_t id);
int		set_up_global(char **cmds, size_t nbr_cmds, t_hash *hash);
int		redirect_input(char *filename, t_command *son, size_t id);
int		redirect_output_trunc(char *filename, t_command *son, size_t id);
int		redirect_output_append(char *filename, t_command *son, size_t id);

//void return
void	echo();
void    builtins();
void	executor();
void	env(t_hash *hash);
void	set_up_signals(void);
void	free_hash(t_hash *hash);
void	easter_eggs(char *flags);
void	easy_splitter(char *str);
void	pwd(char *str, t_hash *hash);
void	unset(char *str, t_hash *hash);
void	add_to_history(char *pipeline);
void	export(char *str, t_hash *hash);
void	solo_copy(char *new, char *str);
void	free_all_and_exit(t_hash *hash);
void	expand_copy(char *new, char *str);
void	tokenizer(char *input, t_hash *hash);
void	execute_line(char *line, t_hash *hash);
void	count_cmds(char *input, size_t *n_cmds);
void	insert_node(t_hash *hash, char *key, char *value);
void	inside_quote_copy(char **str, char **new, char quote);
void	copy_with_expansions(char *str, char *new, t_hash *hash);
void	expansion_loop(char *limiter, t_command *son, size_t id);
void	no_expansion_loop(char *limiter, t_command *son, size_t id);
void	inside_quote_counter(char **str, size_t *counter, char quote);
void	copy_with_expansions_heredoc(char *str, char *new, t_hash *hash);

// char retunr
char	*separator(char *str);
char	*extract_cmd(char **input);
char	**hash_to_matrix(t_hash *hash);
char	*search(t_hash *hash, char *key);
char	*remove_quote_or_expand(char *str);
char	*expand_vars(char *str, t_hash *hash);

// t_node return
t_node	*create_node(char *key, char *value);

// size_t return
size_t	solo_size(char *str);
size_t	expand_size(char *str);
size_t	size_with_values_heredoc(char *str, t_hash *hash);

// pid_t return
pid_t	execute_command(char **args, t_hash *hash);

#endif // minishell.h
