CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11 -Wno-long-long -O0 -O2 -ggdb
BIN = bin
SRC = src
MAIN = program
RM = rm -r -f

compile: $(BIN) 
	$(CC) $(CFLAGS) $(SRC)/$(MAIN).cpp -o $(BIN)/$(MAIN)
$(BIN):
	mkdir $(BIN)
clean:
	$(RM) $(BIN)
valg:
	valgrind $(BIN)/$(MAIN) 
