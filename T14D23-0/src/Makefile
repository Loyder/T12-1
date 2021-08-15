CC=gcc
CFLAGS=-c #-Wall -Werror -Wextra
TRG1=state_sort
SRC1=$(TRG1).c
OBJ1=$(SRC1:.c=.o)
BIN=../build
EXE1=$(BIN)/Quest_1

.PHONY: all clean rebuild

all: $(TRG1)

$(TRG1): $(OBJ1)
	$(CC) $^ -o $(EXE1)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -f *.o ../build/*

rebuild: clean all

git:
	git add .
	git status
	git commit -m '$(c)'
	git push origin develop