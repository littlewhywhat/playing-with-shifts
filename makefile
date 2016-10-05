CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11 -Wno-long-long -O0 -O2 -ggdb
BIN = bin
SRC = src
MAIN = program
TESTWT2SS = testwt2ss
TESTG2WT = testg2wt
RM = rm -r -f
ARGS = data/g2wt/in/graph1 3
DOX = config

all: compile run

compile: $(SRC)/$(MAIN).cpp 
	$(CC) $(CFLAGS) $(SRC)/$(MAIN).cpp -o $(MAIN) 2>&1 | less
run: compile
	./$(MAIN) $(ARGS) 1	
clean:
	rm -f $(MAIN); rm -f $(TESTWT2SS); rm -f $(TESTG2WT)
valg: compile
	valgrind ./$(MAIN) $(ARGS) 1; valgrind ./$(MAIN) $(ARGS) 2; valgrind ./$(MAIN) $(ARGS) 3
gdb: compile
	gdb --args ./$(MAIN) $(ARGS) 1
test:
	./test.sh; ./testg2wt.sh; ./testwt2ss.sh
doxygen:
	doxygen $(DOX)
