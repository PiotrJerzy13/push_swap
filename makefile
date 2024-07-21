# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include -I./libtft
LDFLAGS = -Llibtft -lft

# Directories
SRCDIR = .

# Source files
SOURCES = $(SRCDIR)/stack_operations.c \
          $(SRCDIR)/stack_operations2.c \
          $(SRCDIR)/stack_operations3.c \
          $(SRCDIR)/stack_operations4.c \
          $(SRCDIR)/stack_operations5.c \
          $(SRCDIR)/stack_operations6.c \
          $(SRCDIR)/calibration.c \
          $(SRCDIR)/push_swap.c \
          $(SRCDIR)/sort_3.c \
          $(SRCDIR)/errors.c \
          $(SRCDIR)/main.c \
          $(SRCDIR)/ft_split.c

# Build directory
BUILD_DIR = build

# Object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILD_DIR)/%.o)

# Executable name
EXECUTABLE = push_swap

# Default target
all: $(EXECUTABLE)

# Rule to create the executable
$(EXECUTABLE): $(OBJECTS) libtft/libtft.a
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Rule to create object files in the build directory
$(BUILD_DIR)/%.o: $(SRCDIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Ensure libtft is built
libtft/libtft.a:
	make -C libtft all

# Clean up build files
clean:
	rm -f $(BUILD_DIR)/*.o
	make -C libtft clean

fclean: clean
	rm -f $(EXECUTABLE)
	make -C libtft fclean

re: fclean all

.PHONY: all clean fclean re
