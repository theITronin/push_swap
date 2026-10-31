NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = push_swap.c \
		  algorithms/complex_algorithm.c \
		  algorithms/medium_algorithm.c \
		  algorithms/simple_algorithm.c \
		  algorithms/adaptive_algorithm.c \
		  algorithms/flag_management.c \
		  algorithms/sort_five.c \
		  algorithms/sort_three.c \
		  bench/bench.c

SOURCES_MIX = lst_utils/lst_utils.c \
			  lst_utils/lst_utils_2.c \
			  parse/parse.c \
			  parse/parse_add_array.c \
			  parse/parse_add_params.c \
			  push_swap_ops/op_management.c \
			  push_swap_ops/push_ops.c \
			  push_swap_ops/rotate_ops.c \
			  push_swap_ops/swap_ops.c \
			  push_swap_ops/rev_rotate_ops.c \
			  algorithms/index_disorder.c \

BONUS_SOURCES = bonus/checker.c

OBJS = $(SOURCES:.c=.o)
OBJS_SOURCE = $(SOURCES_MIX:.c=.o)
OBJS_BONUS = $(BONUS_SOURCES:.c=.o)

# RULE TO CREATE THE PROGRAM
$(NAME): $(OBJS) $(OBJS_SOURCE) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_SOURCE) $(LIBFT) -o $(NAME)
	@echo "********************************"
	@echo "Compilation $(NAME) completed"
	@echo "********************************"

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS_SOURCE) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS_SOURCE) $(LIBFT) -o $(NAME_BONUS)
	@echo "********************************"
	@echo "Compilation $(NAME) completed"
	@echo "********************************"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# CREATOR OBJS RULE
%.o: %.c push_swap.h
	@echo "Compiling..."
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c  $< -o $@


all:  $(NAME)

bonus: $(NAME_BONUS)

# RULE: DELETE OBJECT FILES
clean:
	@echo "Deleting objects files (*.o)..."
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS) $(OBJS_BONUS) $(OBJS_SOURCE)

# RULE: DELETE OBJECT FILES AND LIBRARY
fclean: clean
	@echo "Deleting object files and library..."
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME) $(NAME_BONUS)

# RULE: RECOMPILES ALL
re: fclean all
	@echo "Recompiling project..."

# PHONY TARGETS
.PHONY: all clean fclean re bonus
