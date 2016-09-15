CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11 -Wno-long-long -O0 -O2 -ggdb
BIN = bin
SRC = src
MAIN = program
TEST = test
RM = rm -r -f

compile: $(BIN) 
	$(CC) $(CFLAGS) $(SRC)/$(MAIN).cpp -o $(MAIN) 2>&1 | less
tcompile: $(BIN) 
	$(CC) $(CFLAGS) $(SRC)/$(TEST).cpp -o $(MAIN) 2>&1 | less
$(BIN):
	mkdir $(BIN)
clean:
	$(RM) $(BIN)
valg:
	valgrind ./$(MAIN) data/graph 5 1 
gdb:
	gdb --args ./$(MAIN) data/graph 5 1
