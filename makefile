NAME = push_swap
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libtft

SRCS = src/dll_swap.c \
       src/main.c \
       src/utilities.c \
       src/error_handling.c \
	   src/stack_operations.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

libft:
	@$(MAKE) -C $(LIBFTDIR)
	@echo "Library libft.a built successfully."

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re libft
