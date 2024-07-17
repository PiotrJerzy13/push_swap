# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra 

# Project name
NAME = push_swap

# Directories
SRCDIR = src
LIBFTDIR = ./libtft

# Source files
SRCS = $(SRCDIR)/stack_operations1.c \
       $(SRCDIR)/stack_operations2.c \
       $(SRCDIR)/stack_operations3.c \
       $(SRCDIR)/stack_operations4.c \
       $(SRCDIR)/stack_operations5.c \
       $(SRCDIR)/stack_operations6.c \
	   $(SRCDIR)/stack_operations7.c \
       $(SRCDIR)/push_swap.c \
	   $(SRCDIR)/sort_three.c \
	   $(SRCDIR)/error_handling.c \
       $(SRCDIR)/main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Include directories
INCLUDES = -I$(LIBFTDIR)

# Library file
LIBFT = $(LIBFTDIR)/libft.a

# Targets
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)
	@echo "Library libft.a built successfully."

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
