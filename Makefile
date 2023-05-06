NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libs/libft/libft.a
INCLUDES = -I includes -I libs/libft/includes

# vou mudar isso ainda fiquei com preguica e so pra quebrar um galho por enquanto
SRCS_BUILT_INS = srcs/Built_ins/builtins.c \
		srcs/Built_ins/cd.c \
		srcs/Built_ins/echo.c \
		srcs/Built_ins/echo_utils.c \
		srcs/Built_ins/env.c \
		srcs/Built_ins/exit.c \
		srcs/Built_ins/export.c \
		srcs/Built_ins/pwd.c \
		srcs/Built_ins/unset.c

SRCS_ESSENTIALS = srcs/essentials/add_to_history.c \
		srcs/essentials/free_all_and_exit.c

SRCS_HASH_TABLE = srcs/Hash_table/hash_free.c \
		srcs/Hash_table/hash_tab.c

SRCS_LEXER = srcs/Lexer/lexer_easy_splitter.c \
		srcs/Lexer/lexer_expander.c \
		srcs/Lexer/lexer_expander_utils.c \
		srcs/Lexer/lexer_spacer.c \
		srcs/Lexer/lexer_spacer_utils.c

SRCS_PARSER = srcs/parser/parser.c \
		srcs/parser/parser_utils.c

SRCS_OTHERS = srcs/main.c \
		srcs/pipe.c

SRCS = $(SRCS_BUILT_INS) $(SRCS_ESSENTIALS) $(SRCS_HASH_TABLE) $(SRCS_LEXER) $(SRCS_PARSER) $(SRCS_OTHERS)

OBJS_BUILT_INS = $(patsubst srcs/Built_ins/%.c,builds/Built_ins/%.o,$(SRCS_BUILT_INS))
OBJS_ESSENTIALS = $(patsubst srcs/essentials/%.c,builds/essentials/%.o,$(SRCS_ESSENTIALS))
OBJS_HASH_TABLE = $(patsubst srcs/Hash_table/%.c,builds/Hash_table/%.o,$(SRCS_HASH_TABLE))
OBJS_LEXER = $(patsubst srcs/Lexer/%.c,builds/Lexer/%.o,$(SRCS_LEXER))
OBJS_PARSER = $(patsubst srcs/parser/%.c,builds/parser/%.o,$(SRCS_PARSER))
OBJS_OTHERS = $(patsubst %.c,builds/%.o,$(notdir $(SRCS_OTHERS)))

OBJS = $(OBJS_BUILT_INS) $(OBJS_ESSENTIALS) $(OBJS_HASH_TABLE) $(OBJS_LEXER) $(OBJS_PARSER) $(OBJS_OTHERS)


all: CFLAGS += -O2 #flagzinha de otimizacao n se importe por enquanto
all: $(NAME)

debug: CFLAGS += -g
debug: fclean all

$(NAME): $(OBJS)
	@make -C libs/libft
	@printf "\r\033[0;32m[BIN] $(NAME)\033[0m\033[K\n"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

builds/Built_ins/%.o: srcs/Built_ins/%.c
	@mkdir -p builds/Built_ins
	@printf "\r\033[0;33m[BUILD] $@\033[0m\033[K"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

builds/essentials/%.o: srcs/essentials/%.c
	@mkdir -p builds/essentials
	@printf "\r\033[0;33m[BUILD] $@\033[0m\033[K"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

builds/Hash_table/%.o: srcs/Hash_table/%.c
	@mkdir -p builds/Hash_table
	@printf "\r\033[0;33m[BUILD] $@\033[0m\033[K"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

builds/Lexer/%.o: srcs/Lexer/%.c
	@mkdir -p builds/Lexer
	@printf "\r\033[0;33m[BUILD] $@\033[0m\033[K"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

builds/parser/%.o: srcs/parser/%.c
	@mkdir -p builds/parser
	@printf "\r\033[0;33m[BUILD] $@\033[0m\033[K"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

builds/%.o: srcs/%.c
	@mkdir -p builds
	@printf "\r\033[0;33m[BUILD] $@\033[0m\033[K"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C libs/libft
	@printf "\r\033[0;31m[REMOVE] objects\033[0m\033[K\n"
	@rm -rf builds

fclean: clean
	@make fclean -C libs/libft
	@printf "\r\033[0;31m[REMOVE] $(NAME)\033[0m\033[K\n"
	@rm -f $(NAME)

valg: all
	valgrind -q --leak-check=full --show-leak-kinds=all --suppressions=sup ./minishell

gdb: all
	gdb --tui minishell

re: fclean all

.PHONY: all clean fclean re debug