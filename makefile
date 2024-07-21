# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra 
LDFLAGS = -Llibft -lft

# Directories
CFLAGS = -I./include -I./libft -Wall -Wextra -Werror

# Source files
SOURCES = $(SRCDIR)/stack_operations1.c \
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

BUILD_DIR = build

# Object files
OBJECTS = $(SOURCES:%.c=$(BUILD_DIR)/%.o)

EXECUTABLE = push_swap

# Default target
all: $(EXECUTABLE)

# Rule to create the executable
$(EXECUTABLE): $(OBJECTS) libft/libft.a
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Rule to create object files in the build directory
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure libft is built
libft/libft.a:
	make -C libft all

# Clean up build files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	make -C libft clean

fclean: clean
	rm -f $(EXECUTABLE)
	make -C libft fclean

re: fclean all