CC=gcc
CFLAGS=-c # -Wall -Werror -Wextra
BIN=../build
SOURCE1=s21_string_test.c 
SOURCE2=s21_string.c
OBJECT1=$(patsubst %.c,%,$(SOURCE1))
OBJECT2=$(patsubst %.c,%,$(SOURCE2))
EXE1=$(BIN)/Quest_1
EXE2=$(BIN)/Quest_2
EXE3=$(BIN)/Quest_3
EXE4=$(BIN)/Quest_4
EXE5=$(BIN)/Quest_5
EXE6=$(BIN)/Quest_6
EXE7=$(BIN)/Quest_7
.PHONY: all clean rebuild

all: strlen_tests
#strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

strlen_tests: $(EXE1)
$(EXE1): $(OBJECT1)_q1.o $(OBJECT2)_q1.o
	$(CC) $^ -o $@
$(OBJECT1)_q1.o: $(SOURCE1)
	$(CC) -DQUEST1 $(CFLAGS) $^ -o $@
$(OBJECT2)_q1.o: $(SOURCE2)
	$(CC) $(CFLAGS) $^ -o $@

strcmp_tests: $(EXE2)
$(EXE2): $(OBJECT1)_q2.o $(OBJECT2)_q2.o
	$(CC) $^ -o $@
$(OBJECT1)_q2.o: $(SOURCE1)
	$(CC) -DQUEST2 $(CFLAGS) $^ -o $@
$(OBJECT2)_q2.o: $(SOURCE2)
	$(CC) $(CFLAGS) $^ -o $@
	
strcpy_tests: $(EXE3)
$(EXE3): $(OBJECT1)_q3.o $(OBJECT2)_q3.o
	$(CC) $^ -o $@
$(OBJECT1)_q3.o: $(SOURCE1)
	$(CC) -DQUEST3 $(CFLAGS) $^ -o $@
$(OBJECT2)_q3.o: $(SOURCE2)
	$(CC) $(CFLAGS) $^ -o $@

strcat_tests: $(EXE4)
$(EXE4): $(OBJECT1)_q4.o $(OBJECT2)_q4.o
	$(CC) $^ -o $@
$(OBJECT1)_q4.o: $(SOURCE1)
	$(CC) -DQUEST4 $(CFLAGS) $^ -o $@
$(OBJECT2)_q4.o: $(SOURCE2)
	$(CC) $(CFLAGS) $^ -o $@

strchr_tests: $(EXE5)
$(EXE5): $(OBJECT1)_q5.o $(OBJECT2)_q5.o
	$(CC) $^ -o $@
$(OBJECT1)_q5.o: $(SOURCE1)
	$(CC) -DQUEST5 $(CFLAGS) $^ -o $@
$(OBJECT2)_q5.o: $(SOURCE2)
	$(CC) $(CFLAGS) $^ -o $@

strstr_tests: $(EXE6)
$(EXE6): $(OBJECT1)_q6.o $(OBJECT2)_q6.o
	$(CC) $^ -o $@
$(OBJECT1)_q6.o: $(SOURCE1)
	$(CC) -DQUEST6 $(CFLAGS) $^ -o $@
$(OBJECT2)_q6.o: $(SOURCE2)
	$(CC) $(CFLAGS) $^ -o $@

strtok_tests: $(EXE7)
$(EXE7): $(OBJECT1)_q7.o $(OBJECT2)_q7.o
	$(CC) $^ -o $@
$(OBJECT1)_q7.o: $(SOURCE1)
	$(CC) -DQUEST7 $(CFLAGS) $^ -o $@
$(OBJECT2)_q7.o: $(SOURCE2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o **/*.o
	rm $(BIN)/*

rebuild: clean strlen_tests