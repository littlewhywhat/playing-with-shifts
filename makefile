CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11 -Wno-long-long -O0 -O2 -ggdb
BIN = bin
SRC = src
MAIN = main
EXEC = playshift
TEST1 = testl2ss
TEST2 = testg2l
RM = rm -r -f
ARGS = -g data/g2wt/in/graph1 -w 3 -p maxbcnt -m
DOX = config

all: compile run

compile: $(SRC)/$(MAIN).cpp 
	$(CC) $(CFLAGS) $(SRC)/$(MAIN).cpp -o $(EXEC) 2>&1 | less
run: compile
	./$(EXEC) $(ARGS) 1	
clean:
	rm -f $(EXEC); rm -f $(TEST1); rm -f $(TEST2)
valg: compile
	valgrind ./$(EXEC) $(ARGS) 1; valgrind ./$(EXEC) $(ARGS) 2; valgrind ./$(EXEC) $(ARGS) 3
gdb: compile
	gdb --args ./$(EXEC) $(ARGS) 1
test:
	./test.sh; ./$(TEST1).sh ./$(TEST2).sh;
doxygen:
	doxygen $(DOX)
