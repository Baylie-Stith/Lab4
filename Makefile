# Makefile
# CC becomes gcc when called and CFLAGS turns .c to .o files and shows all warnings
CC = gcc
CFLAGS = -c -Wall

# Creates variable that contians all necessary .o files to compile the program
OBJECTS = task1.o task2.o

# Compiles the program using the .o files and creates an executable called prog
prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog

# Compiles the .c files into .o files using the CC and CFLAGS variables
%.o: %.c
	$(CC) $(CFLAGS) $<

# Cleans up the directory by removing all .o files and the executable prog
clean:
	rm -rf *.o prog