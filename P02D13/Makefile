CC=gcc
CFLAGS=-c -g -Wall -Werror -Wextra
DIR_BIN=build
DIR_OBJ=obj
DIR_SRC=src
F1=test_hash
F2=hash
LIST=$(F1) $(F2)
CLIST=$(addsuffix .c, $(LIST))
OLIST=$(addsuffix .o, $(LIST))
# OLIST=$(CLIST .c=.o)
# SRC=$(addprefix $(DIR_SRC)/, $(CLIST))
OBJ=$(addprefix $(DIR_OBJ)/, $(OLIST))
EXE=$(DIR_BIN)/$(F1).exe

.PHONY: all clean rebuild

all: $(F1) 

$(F1) : $(OBJ)
	$(CC) -g $^ -o $(EXE)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(DIR_OBJ)/*.o $(DIR_BIN)/*.exe

rebuild: clean all

go: all
	./$(EXE)

git:
	git add .
	git status
	git commit -m '$(c)'
	git push origin develop