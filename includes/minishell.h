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

# define PROMPT "Minishell >$ "
// # define ERR_FORK "\e[1;5;31mms: forking error\e[0m"
# define ERR_QUOTE "\e[1;5;31mms: close this quote \e[1m`%c`\n\e[0m"
# define ERR_READING "\e[1;5;31mms: read error\e[0m"
# define ERR_WRITING "\e[1;5;31mms: write error\e[0m"
# define WAR_HEREDOC "\e[1;33mwarning: finish with EOF, expected `%s`\e[0m"
# define HEREDOC_PATH "/tmp/.heredoc"
# define ERR_INPUT_DIR "\e[1;5;31mms: read error: %s\n\e[0m"
# define HEREDOC_PROMPT "here-document> "
# define ERR_UNS_SYNTAX "\e[1;5;31mms: unsuported syntax \e[1m`%s`\n\e[0m"
# define ERR_EOL_SYNTAX "\e[1;5;31mms: syntax error \e[1m`EOL`\e[0m"
# define ERR_NOW_SYNTAX "\e[1;5;31mms: syntax error \e[1m`%s`\n\e[0m"
# define ERR_NEXT_SYNTAX "\e[1;5;31mms: syntax error after \e[1m`%s`\n\e[0m"

# define REDI_OK 0
# define REDI_ERR 1
# define REDI_SIGNAL -1

# define TRUNC 01101
# define APPEND 02101
# define HEREDOC 01102
# define SIGNAL_INT 130
# define PERM_CREATE 0644

// ! GLOBAL: NEVER DIRECTELY INCREMENT ANY POINTER INSIDE THE STRUCT;
extern t_pipe	g_shell;

// int return
int		cd(char *str);
int		pipe_case(char **splited_pline);
int		parser(char *str, t_hash *hash);
int		write_to_case(char **splited_pline);
int		redirection(char *str, t_hash *hash, t_command *son);
int		intersections(char *str, char inter);
int		read_from_case(char **splited_pline);
int		unclosed_quotes_case(char **pipeline, char quote);

//void return
void	env(t_hash *hash);
void	set_up_signals(void);
void	free_hash(t_hash *hash);
void	easter_eggs(char *flags);
void	easy_splitter(char *str);
void	pwd(char *str, t_hash *hash);
void	echo(char *str, t_hash *hash);
void	unset(char *str, t_hash *hash);
void	add_to_history(char *pipeline);
void	export(char *str, t_hash *hash);
void	free_all_and_exit(t_hash *hash);
void	builtins(char *input, t_hash *hash);
void	tokenizer(char *input, t_hash *hash);
void	execute_line(char *line, t_hash *hash);
void	count_cmds(char *input, size_t *n_cmds);
void	heredoc(t_hash *hash, t_redirect *this);
void	insert_node(t_hash *hash, char *key, char *value);
void	inside_quote_copy(char **str, char **new, char quote);
void	copy_with_expansions(char *str, char *new, t_hash *hash);
void	inside_quote_counter(char **str, size_t *counter, char quote);

// char retunr
char	*separator(char *str);
char	*extract_cmd(char **input);
char	*search(t_hash *hash, char *key);
char	*expand_vars(char *str, t_hash *hash);
// t_node return
t_node	*create_node(char *key, char *value);

// new functions, analyze they before putting in the right place
int	    isbuiltin(char *check);
int		reading_invalid(char *file, t_hash *hash);
int		writing_invalid(char *file, t_hash *hash);
int		redirect_invalid(char **split_pline, t_hash *hash);

// pid_t return
pid_t	execute_command(char **args, t_hash *hash);

#endif // minishell.h
