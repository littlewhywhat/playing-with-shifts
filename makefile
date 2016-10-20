CPPFLAGS = -g -Wall -pedantic -std=c++11 -Wno-long-long -O0 -O2 -ggdb
OBJDIR = bin
SRCDIR = src
SOURCES=$(shell find ./$(SRCDIR) -name '*.cpp' -printf "%f ")
OBJECTS=$(addprefix $(OBJDIR)/, $(SOURCES:%.cpp=%.o))
EXEC = playshift
TEST1 = testl2ss
TEST2 = testg2l
RM = rm -r -f
ARGS = -g data/g2wt/in/graph1 -w 3 -p maxbcnt -m
DOX = config
DIRECT = 2>&1 | less

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(EXEC) $(DIRECT)
$(OBJECTS): | $(OBJDIR)
$(OBJDIR)/$(EXEC).o: $(SRCDIR)/$(EXEC).cpp
	$(CXX) $(CPPFLAGS) $< -c -o $@ $(DIRECT)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	$(CXX) $(CPPFLAGS) $< -c -o $@ $(DIRECT)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) $(OBJDIR); $(RM) $(EXEC); $(RM) $(TEST1); $(RM) $(TEST2)
#valg: compile
#	valgrind ./$(EXEC) $(ARGS) 1; valgrind ./$(EXEC) $(ARGS) 2; valgrind ./$(EXEC) $(ARGS) 3
#gdb: compile
#	gdb --args ./$(EXEC) $(ARGS) 1
#test:
#	./test.sh; ./$(TEST1).sh ./$(TEST2).sh;
doxygen:
	doxygen $(DOX)
