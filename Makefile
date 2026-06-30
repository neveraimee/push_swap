NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

SRCS = main.c \
       stack.c \
	   stack2.c \
       operations.c \
	   operations2.c \
	   operations3.c \
       chunk_sort.c \
       adaptive_sort.c \
       write_bench.c \
       bubble_sort.c \
       radix_sort.c \
       disorder.c \
       parse.c \
       flags.c \
       split.c \
	   build.c \
	   free_utils.c \
	   utils.c \
	   small_sort.c

OBJS = $(SRCS:.c=.o)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
