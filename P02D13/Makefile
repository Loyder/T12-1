CC=gcc
CFLAGS=-c -g -Wall -Werror -Wextra
DIR_BIN=build
DIR_OBJ=obj
DIR_SRC=src
S1=game_life
S2=hash
LIST=$(S1) $(S2)
CLIST=$(addsuffix .c, $(LIST))
OLIST=$(addsuffix .o, $(LIST))
OBJ=$(addprefix $(DIR_OBJ)/, $(OLIST))
EXE=$(DIR_BIN)/$(S1).exe

.PHONY: all clean rebuild

all: $(S1) 

$(S1) : $(OBJ)
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