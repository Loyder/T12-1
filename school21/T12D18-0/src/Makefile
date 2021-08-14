CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
SRC1=main_module_entry_point.c
SRC2=print_module.c
SRC=$(SRC1) $(SRC2)
OBJ=$(SRC:.c=.o)
BIN=../build
EXE1=$(BIN)/Quest_1

.PHONY: all clean rebuild

all: print_module

print_module: $(OBJ)
	$(CC) $^ -o $(EXE1)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o ../build/*

rebuild: clean all