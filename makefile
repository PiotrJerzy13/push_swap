NAME = push_swap
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libtft

SRCS = src/stack_operations.c \
	   src/stack_operations2.c \
	   src/stack_operations3.c \
       src/main.c \
       src/utilities.c \
       src/error_handling.c \
	   src/sort35.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

$(LIBFTDIR)/$(LIBFTNAME):
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
