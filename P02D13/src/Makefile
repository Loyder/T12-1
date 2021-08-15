CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
TRG1=test_hash
SRC1=$(TRG1).c
OBJ1=$(SRC1:.c=.o)
BIN=../build
EXE1=$(BIN)/$(TRG1).exe

.PHONY: all clean rebuild

all: test_hash

test_hash: test_hash.o hash.o
	gcc hash.o test_hash.o -o ../build/test_hash.exe -g

test_hash.o: test_hash.c
	gcc -c test_hash.c
hash.o: hash.c
	gcc -c hash.c

clean:
	rm -f *.o ../build/*

rebuild: clean all

git:
	git add .
	git status
	git commit -m '$(c)'
	git push origin develop