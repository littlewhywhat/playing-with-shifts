CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11 -Wno-long-long -O0 -O2 -ggdb
BIN = bin
SRC = src
MAIN = program
RM = rm -r -f

compile: $(BIN) 
	$(CC) $(CFLAGS) $(SRC)/$(MAIN).cpp -o $(MAIN) 2>&1 | less
$(BIN):
	mkdir $(BIN)
clean:
	$(RM) $(BIN)
valg:
	valgrind ./$(MAIN) data/graph 5 1 
gdb:
	gdb --args ./$(MAIN) data/graph 5 1
test: $(BIN)/$(MAIN) 
	./$(BIN)/$(MAIN) > ./$(BIN)/output; diff ./$(BIN)/output ./test/output0
