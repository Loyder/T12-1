CC=gcc
PREFIX1=../data_libs
PREFIX2=../data_module
PREFIX3=../yet_another_decision_module
BUILD_DIR=../../build
CFLAGS=-c -Wall -Werror -Wextra
SOURCE11=$(PREFIX1)/data_io.c
SOURCE12=$(PREFIX1)/data_stat.c
SOURCE2=$(PREFIX2)/data_process.c
SOURCE3=$(PREFIX3)/decision.c
SOURCE4=main_executable_module.c
SOURCES=$(SOURCE11) $(SOURCE12) $(SOURCE2) $(SOURCE3) $(SOURCE4)
SOURCESQ5=$(SOURCE11) $(SOURCE2) $(SOURCE3) $(SOURCE4)
SOURCESQ6=$(SOURCE11) $(SOURCE12) $(SOURCE3) $(SOURCE4)
OBJECT12=$(SOURCE12:.c=.o)
OBJECTS=$(SOURCES:.c=.o)
OBJECTSQ5=$(SOURCESQ5:.c=.o)
OBJECTSQ6=$(SOURCESQ6:.c=.o)
EXEQ3=$(BUILD_DIR)/Quest_3
EXEQ5=$(BUILD_DIR)/Quest_5
EXEQ6=$(BUILD_DIR)/Quest_6

.PHONY: all clean rebuild

all: $(EXEQ3)

$(EXEQ3): $(OBJECTS)
	$(CC) $^ -o $@

build_with_static: data_stat.a $(EXEQ5)

$(EXEQ5): $(OBJECTSQ5)
	$(CC) $(PREFIX1)/data_stat.a $^ -o $@

data_stat.a: $(OBJECT12)
	ar -rcs $(PREFIX1)/$@ $<

build_with_dynamic: data_process.so $(EXEQ6)

$(EXEQ6): $(OBJECTSQ6) 
	$(CC) $(PREFIX2)/data_process.so $^ -o $@

data_process.so:
	$(CC) -shared -fPIC $(SOURCE12) $(SOURCE2) -o $(PREFIX2)/$@

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	find ../ -name "*.o" -type f -delete

rebuild: clean all
