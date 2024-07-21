# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libtft

# Source files
SOURCES = stack_operations.c stack_operations2.c stack_operations3.c stack_operations4.c stack_operations5.c stack_operations6.c push_swap.c sort_3.c errors.c main.c 

# Build directory
BUILD_DIR = build

# Object files
OBJECTS = $(SOURCES:%.c=$(BUILD_DIR)/%.o)

# Executable name
EXECUTABLE = push_swap

# Default target
all: $(EXECUTABLE)

# Rule to create the executable
$(EXECUTABLE): $(OBJECTS) libtft/libtft.a
	$(CC) $(OBJECTS) -o $@ -L./libtft libtft/libtft.a

# Rule to create object files in the build directory
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure libtft is built
libtft/libtft.a:
	make -C libtft all

# Clean up build files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	make -C libtft clean

fclean: clean
	rm -f $(EXECUTABLE)
	make -C libtft fclean

re: fclean all

.PHONY: all clean fclean re

