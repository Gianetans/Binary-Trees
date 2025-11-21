# Makefile for Binary Search Tree Program

CC=gcc
CFLAGS=-I.

# Target to build the binary search tree program
all: bst

# Rule to compile the binary search tree
bst: bst.o
	$(CC) -o bst bst.o

# Rule for creating object file
bst.o: bst.c
	$(CC) -c bst.c $(CFLAGS)

# Clean up the compiled files
clean:
	rm -f bst bst.o
