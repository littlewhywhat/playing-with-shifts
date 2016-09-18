CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11 -Wno-long-long -O0 -O2 -ggdb
BIN = bin
SRC = src
MAIN = program
TEST = tprogram
RM = rm -r -f
ARGS = data/graph 3 1

all: clean compile

compile: $(SRC)/$(MAIN).cpp 
	$(CC) $(CFLAGS) $(SRC)/$(MAIN).cpp -o $(MAIN) 2>&1 | less
test: tcompile
	./test.sh; rm $(TEST)	
tcompile: 
	$(CC) $(CFLAGS) $(SRC)/test.cpp -o $(TEST) 2>&1 | less
run: compile
	./$(MAIN) $(ARGS)	
clean:
	rm -f $(MAIN); rm -f $(TEST);
valg: compile
	valgrind ./$(MAIN) $(ARGS) 
gdb: compile
	gdb --args ./$(MAIN) $(ARGS)
