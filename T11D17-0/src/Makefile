CC=gcc
CFLAGS=-c  -Wall -Werror -Wextra
SRC1=dmanager_module.c
SRC2=polynomial.c
SRC3=stack.c
OBJ1=$(SRC1:.c=.o)
OBJ2=$(SRC2:.c=.o)
OBJ3=$(SRC3:.c=.o)
BIN=../build
EXE1=$(BIN)/Quest_1
EXE2=$(BIN)/Quest_2

.PHONY: all clean rebuild

all: door_struct # polynomial

door_struct: $(OBJ1)
	$(CC) $^ -o $(EXE1)

polynomial: $(OBJ2)
	$(CC) $^ -o $(EXE2)

stack_test: $(OBJ3)
	$(CC) $^ -o $(EXE3)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o ../build/*

rebuild: clean all
