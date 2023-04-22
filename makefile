# Set the compiler to gcc
CC=gcc

# Set the compiler flags
CFLAGS=-Wall -Wextra -O2
 
# Set the source and object file directories
SRCDIR=src
OBJDIR=obj
BINDIR=bin
EXEC=LinkAlarm

# Define the source and object file lists
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Define the default target
all: $(BINDIR) $(BINDIR)/$(EXEC)

# Define the rule to compile the source files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Define the rule to link the object files into an executable
$(BINDIR)/$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Define the rule to create the object file directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Define the rule to create the binary file directory
$(BINDIR):
	mkdir -p $(BINDIR)

# Define the clean target
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Declare the phony targets
.PHONY: all clean


