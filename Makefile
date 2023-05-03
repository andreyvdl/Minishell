NAME = minishell
HEADER = ./includes
SOURCES = ./srcs
BUILD_DIR = ./builds

OBJS = $(patsubst $(SOURCES)/%.c, $(BUILD_DIR)/%.o, $(wildcard $(SOURCES)/*.c))

COMP = cc -Wall -Werror -Wextra -g3

COLOR_BIN = \033[32m
COLOR_RM = \033[31m
COLOR_BUILD = \033[33m
COLOR_DEP = \033[34m
COLOR_RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(COLOR_BIN)[BIN]$(COLOR_RESET) Creating $@..."
	@make -C ./libs/libft
	@$(COMP) -o $@ $^ -L./libs/libft/ -lft -lreadline

$(BUILD_DIR)/%.o: $(SOURCES)/%.c | $(BUILD_DIR)
	@echo "$(COLOR_BUILD)[BUILD]$(COLOR_RESET) Compiling $<..."
	@$(COMP) -c -o $@ $<

$(BUILD_DIR):
	@echo "$(COLOR_DEP)[DEP]$(COLOR_RESET) Creating $@ directory..."
	@mkdir -p $@

clean:
	make clean -C  ./libs/libft/
	@echo "$(COLOR_RM)[RM]$(COLOR_RESET) Removing objects..."
	@rm -rf $(BUILD_DIR)

fclean: clean
		make fclean -C  ./libs/libft/
	@echo "$(COLOR_RM)[RM]$(COLOR_RESET) Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
