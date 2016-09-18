CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11 -Wno-long-long -O0 -O2 -ggdb
BIN = bin
SRC = src
MAIN = program
TESTWT2SS = testwt2ss
TESTG2WT = testg2wt
RM = rm -r -f
ARGS = data/graph 3 1

all: compile run

compile: $(SRC)/$(MAIN).cpp 
	$(CC) $(CFLAGS) $(SRC)/$(MAIN).cpp -o $(MAIN) 2>&1 | less
run: compile
	./$(MAIN) $(ARGS)	
clean:
	rm -f $(MAIN); rm -f $(TESTWT2SS); rm -f $(TESTG2WT)
valg: compile
	valgrind ./$(MAIN) $(ARGS) 
gdb: compile
	gdb --args ./$(MAIN) $(ARGS)
