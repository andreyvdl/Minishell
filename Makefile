#============ [FILES] ==========
NAME = minishell

FILES = builtins.c cd.c echo.c env.c exit_utils.c exit.c export.c father_cd.c father_echo.c father_env.c father_exit.c father_export.c father_pwd.c father_unset.c pwd.c unset.c \
		add_to_history.c filename_too_big.c free_all_and_exit.c hash_to_matrix.c isbuiltin.c remove_expand_utils.c remove_expand_utils2.c remove_quote_or_expand.c solo_utils.c \
		execution_check.c executor.c father_execute.c free_son.c guide_sons.c is_directory.c open_redirect.c pre_executor.c system_exec.c\
		hash_free.c hash_remove.c hash_tab.c \
		lexer_easy_splitter.c lexer_spacer_utils.c lexer_spacer.c \
		parser.c parser_utils.c \
		append.c heredoc_utils.c heredoc_utils2.c heredoc.c input.c redirect.c trunc.c \
		deslocate_expansion.c fill_son.c token_constructor_utils.c token_constructor.c token_setup_global.c \
		easter_eggs.c main.c signals.c


OBJS = $(addprefix $(BUILDS)/, $(FILES:.c=.o))

DEP = $(OBJS:.o=.d)

LIBFT = $(LIBFTDIR)libft.a

#================= [DIRS] ===================
SRCS = ./srcs
VPATH = Built_ins essentials executor Hash_table  Lexer parser  redirections Tokenizer
VPATH := $(SRCS) $(addprefix $(SRCS)/, $(VPATH))
HEADER = ./includes ./libs/libft/includes
HEADER := $(addprefix -I, $(HEADER))
LIBFTDIR = ./libs/libft/
BUILDS = ./builds

#=================== [CONFIG_COMP] ==========
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
DEPFLAGS = -MMD -MF

#===================== [COMMANDS] ===========
DEL = rm -rf
MKDIR = mkdir -p

#=====================[MESSAGES]=============

DEL_MSG				= @printf "[\e[0;31m DEL \e[0m] "
BIN_MSG				= @printf "[\e[0;32m BIN \e[0m] "
BLD_MSG				= @printf "[\e[0;34m BLD \e[0m] "
MKD_MSG				= @printf "[\e[0;35m MKD \e[0m] "

# =================[BASIC_RULES] ============

all: $(NAME)

$(NAME): $(LIBFT) $(BUILDS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADER)  $(LIBFT) -o $(NAME) -lreadline

clean:
	$(DEL) $(BUILDS)
	@make clean -C $(LIBFTDIR)

fclean: clean
	$(DEL) ./minishell
	@make fclean -C $(LIBFTDIR)

re: fclean all

# =================[OTHER_RULES]============
$(BUILDS):
	@$(MKDIR) $@

$(BUILDS)/%.o:%.c
	$(BLD_MSG)
	@printf "Building ... %s\n" $@
	@$(CC) $(CFLAGS) -c $(HEADER) $< -o $@ $(DEPFLAGS) $(@:.o=.d)

$(LIBFT):
	@make -C $(LIBFTDIR)

v:all
	valgrind -q --leak-check=full --show-leak-kinds=all --trace-children=yes --suppressions=sup --track-fds=yes --track-origins=yes --trace-children-skip='*/bin/*,*/sbin/*' ./minishell
#				checa leak		mostra leak				segue child			suprime erros		marca fds		marca var n init	ignora vazamento dos binarios

vq:all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --suppressions=sup --track-fds=yes --track-origins=yes --trace-children-skip='*/bin/*,*/sbin/*' -q ./minishell
#				checa leak		mostra leak				segue child			suprime erros		marca fds		marca var n init	ignora vazamento dos binarios		silencioso

gdb:all
	gdb --tui minishell

# ============ [Target-sepecific Directives]==========
.PHONY: all clean fclean re v vq gdb

# =============[Dependency Inclusion Directive] ======
-include ${DEP}
