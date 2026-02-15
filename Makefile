NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_FOLDER = src
OBJ_FOLDER = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

READLINE_INC = -I/opt/homebrew/opt/readline/include
READLINE_LIB = -L/opt/homebrew/opt/readline/lib -lreadline

INCLUDES = -I include -I $(LIBFT_DIR) $(READLINE_INC)

SRCS = $(SRC_FOLDER)/shell/main.c \
	$(SRC_FOLDER)/shell/line_exec.c \
	$(SRC_FOLDER)/shell/line_utils.c \
	$(SRC_FOLDER)/signals/signal_modes.c \
	$(SRC_FOLDER)/signals/signals_heredoc.c \
	$(SRC_FOLDER)/lexer/lexer_lex.c \
	$(SRC_FOLDER)/lexer/lexer_op.c \
	$(SRC_FOLDER)/lexer/lexer_tokens.c \
	$(SRC_FOLDER)/lexer/lexer_utils.c \
	$(SRC_FOLDER)/lexer/lexer_word.c \
	$(SRC_FOLDER)/parser/parser_args.c \
	$(SRC_FOLDER)/parser/parser_cmd.c \
	$(SRC_FOLDER)/parser/parser_main.c \
	$(SRC_FOLDER)/parser/ast.c \
	$(SRC_FOLDER)/exec/exec_builtin.c \
	$(SRC_FOLDER)/exec/exec_pipeline.c \
	$(SRC_FOLDER)/exec/exec_spawn.c \
	$(SRC_FOLDER)/exec/exec_pipeline_spawn.c \
	$(SRC_FOLDER)/exec/exec_pipeline_utils.c \
	$(SRC_FOLDER)/exec/exec_child.c \
	$(SRC_FOLDER)/exec/exec_path.c \
	$(SRC_FOLDER)/exec/exec_redir.c \
	$(SRC_FOLDER)/exec/exec_utils.c \
	$(SRC_FOLDER)/env/env_unset.c \
	$(SRC_FOLDER)/env/env_utils.c \
	$(SRC_FOLDER)/env/env_env.c \
	$(SRC_FOLDER)/env/env_get.c \
	$(SRC_FOLDER)/builtins/builtin_cd.c \
	$(SRC_FOLDER)/builtins/builtin_echo.c \
	$(SRC_FOLDER)/builtins/builtin_export.c \
	$(SRC_FOLDER)/builtins/builtin_env.c \
	$(SRC_FOLDER)/builtins/builtins_utils.c \
	$(SRC_FOLDER)/builtins/builtin_exit.c \
	$(SRC_FOLDER)/builtins/builtin_pwd.c \
	$(SRC_FOLDER)/expand/expand_utils.c \
	$(SRC_FOLDER)/expand/expand_word.c \
	$(SRC_FOLDER)/expand/expand_word_utils.c \
	$(SRC_FOLDER)/expand/expand_cmd.c \
	$(SRC_FOLDER)/heredoc/hd_name.c \
	$(SRC_FOLDER)/heredoc/hd_write.c \
	$(SRC_FOLDER)/heredoc/hd_loop.c \
	$(SRC_FOLDER)/heredoc/hd_process.c \
	$(SRC_FOLDER)/heredoc/hd_setup.c \
	$(SRC_FOLDER)/heredoc/heredoc_utils.c \
	$(SRC_FOLDER)/terminal/termios.c

OBJS = $(patsubst $(SRC_FOLDER)/%.c,$(OBJ_FOLDER)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_LIB) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_FOLDER):
	@mkdir -p $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c | $(OBJ_FOLDER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_FOLDER)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory fclean

re: fclean all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re valgrind