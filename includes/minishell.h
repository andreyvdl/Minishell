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

// prompts definitions
# if defined(__APPLE__) || defined(__MACH__)
#  define PROMPT "\e[1;34m👤  Minishell\e[0m\n  \e[0;35m🍎\e[0m\e[1;33m↳ \e[0m"
#  define HEREDOC_PROMPT "🍎 here-doc> "
# elif defined(_WIN32) || defined(_WIN64) || defined(__CYWIN__)
#  define PROMPT "\e[1;34m👤  Minishell\e[0m\n  \e[0;35m💾\e[0m\e[1;33m↳ \e[0m"
#  define HEREDOC_PROMPT "💾 here-doc> "
# elif defined(__linux__) || defined(unix) || defined(__unix) || \
defined(__unix__)
#  define PROMPT "\e[1;34m👤  Minishell\e[0m\n  \e[0;35m🐧\e[0m\e[1;33m↳ \e[0m"
#  define HEREDOC_PROMPT "🐧 here-doc> "
# elif defined(__FreeBSD__)
#  define PROMPT "\e[1;34m👤  Minishell\e[0m\n  \e[0;35m😈\e[0m\e[1;33m↳ \e[0m"
#  define HEREDOC_PROMPT "😈 here-doc> "
# else
#  define PROMPT "\e[1;34m👤  Minishell\e[0m\n  \e[0;35m💻\e[0m\e[1;33m↳ \e[0m"
#  define HEREDOC_PROMPT "💻 here-doc> "
# endif
# define HEREDOC_PATH "/tmp/.heredoc"

// 💻🖥️ emojis do windows, comparar com o do linux da 42

// error messages
# define ERR_DUP "\e[1;5;31mms: dup error\e[0m (⊙_(⊙_⊙)_⊙)"
# define ERR_STAT "\e[1;5;31mms: stat error\e[0m (╯‵□′)╯︵┻━┻"
# define ERR_FORK "\e[1;5;31mms: fork error\e[0m (⊙_⊙)？"
# define ERR_PIPE "\e[1;5;31mms: pipe error\e[0m (⊙_⊙;)"
# define ERR_DUP_2 "\e[1;5;31mms: dup2 error\e[0m (⊙_(⊙_⊙)_⊙)"
# define ERR_QUOTE "\e[1;5;31mms: close this quote\e[1m`%c`\e[0m (╬▔皿▔)╯\n"
# define ERR_ACCESS "\e[1;5;31mms: access error\e[0m (っ °Д °;)っ"
# define ERR_EXECVE "\e[1;5;31mms: execve error\e[0m (x_x)"
# define ERR_READING "\e[1;5;31mms: input error\e[0m (＠_＠;)"
# define ERR_WRITING "\e[1;5;31mms: output error\e[0m (＠_＠;)"
# define ERR_HEREDOC "\e[1;5;31mms: heredoc error... congrats...?\e[0m \
ㄟ( ▔, ▔ )ㄏ\n"
# define WAR_HEREDOC "\e[1;33mms: finish with EOF, expected `%s`\e[0m \
༼ つ ◕_◕ ༽つ\n"
# define ERR_EXEC_DIR "\e[1;5;31mms: execution error: %s\e[0m (＠_＠;)\n"
# define ERR_FILENAME "\e[1;5;31mms: filename error: %s\e[0m \
┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻\n"
# define ERR_INPUT_DIR "\e[1;5;31mms: input error: %s\e[0m (＠_＠;)\n"
# define ERR_UNS_SYNTAX "\e[1;5;31mms: unsuported syntax \e[1m`%s`\e[0m \
╰（‵□′）╯\n"
# define ERR_EOL_SYNTAX "\e[1;5;31mms: syntax error \e[1m`EOL`\e[0m ╰（‵□′）╯"
# define ERR_NOW_SYNTAX "\e[1;5;31mms: syntax error \e[1m`%s`\e[0m ╰（‵□′）╯\n"
# define ERR_NEXT_SYNTAX "\e[1;5;31mms: syntax error after \e[1m`%s`\e[0m \
╰（‵□′）╯\n"
# define ERR_CMD_NOT_FOUND "\e[1;5;31mcommand not found: \e[1m`%s`\e[0m \
┗( T﹏T )┛\n"
# define ERR_CMD_NOT_FOUND_2 "\e[1;5;31m(PATH not set)command not found: \
\e[1m`%s`\e[0m ┗( T﹏T )┛\n"

// dev macros
# define FT_EISDIR 21
# define CMD_NOT_FOUND 127
# define REDIRECT_ERROR -42
# define FT_ENAMETOOLONG 36
# define FILENAME_MAX_LEN 255
# define EXEC_WENT_WRONG 126

// dev returns
# define REDI_OK 0
# define REDI_ERR 1
# define SIGNAL_INT -130
# define REDI_SIGNAL -1

// flags
# define NONE 00
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
int		filename_too_big(char *filename);
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
void	pwd();
void	env();
void	echo();
void	builtins();
void	executor(void);
void	free_son(void);
void	pre_executor(void);
void	father_execute(void);
void	set_up_signals(void);
void	free_hash(t_hash *hash);
void	is_directory(char *path);
void	easter_eggs(char *flags);
void	easy_splitter(char *str);
void	execution_check(char *path);
void	unset(char *str, t_hash *hash);
void	add_to_history(char *pipeline);
void	export(char *str, t_hash *hash);
void	solo_copy(char *new, char *str);
void	free_all_and_exit(t_hash *hash);
void	guide_sons(int *pipe, size_t id);
void	expand_copy(char *new, char *str);
void	open_redirect(int *pipe, size_t id);
void	tokenizer(char *input, t_hash *hash);
void	count_cmds(char *input, size_t *n_cmds);
void	system_exec(char **old_argv, char **old_envp);
void	insert_node(t_hash *hash, char *key, char *value);
void	inside_quote_copy(char **str, char **new, char quote);
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

// t_node return
t_node	*create_node(char *key, char *value);

// size_t return
size_t	solo_size(char *str);
size_t	expand_size(char *str);
size_t	size_with_values_heredoc(char *str, t_hash *hash);

// pid_t return
pid_t	execute_command(char **args, t_hash *hash);

#endif // minishell.h
