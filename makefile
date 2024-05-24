NAME = push_swap
FTPRINTNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
FTPRINTDIR = ./ft_printf

SRCS = src/stack_operations.c \
	   src/stack_operations2.c \
	   src/stack_operations3.c \
	   src/stack_operations4.c \
       src/main.c \
       src/utilities.c \
       src/error_handling.c \
	   src/sort3.c \
	   src/algorithm.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FTPRINTDIR)/$(FTPRINTNAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(FTPRINTDIR) -lftprintf

$(FTPRINTDIR)/$(FTPRINTNAME):
	@$(MAKE) -C $(FTPRINTDIR)
	@echo "Library libftprintf.a built successfully."

%.o: %.c
	$(CC) $(CFLAGS) -I$(FTPRINTDIR)/libft -I$(FTPRINTDIR)/src -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(FTPRINTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FTPRINTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
