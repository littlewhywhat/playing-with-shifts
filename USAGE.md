printer single parameters:

-nores don't output player max score
-nolang don't output language
-nogame don't output list of won strategies
-test output specific test prefixes
-filter output only specific rooms (ones with difference in max score)

arguments parser doesn't care about order and if there are some useless arguments - 
as long as it can find necessary ones it will do the work.
all parameters are either single tags or followed by string with value.


// general
-f path

// playshift
output specified by printer args
plays game specified by mode, word length, player.
-m mode (more than one could be specified)
-w word length
-p player

// playshift language builders
graph, lang
-f path to file, prefix of folder files
-n number_of_files (by default one and -f is file)
-g | -l  to turn on

used: 
./playshift -g -f file -w 10 -m 10
./playshift -l -f file -w 10 -m 2 1
./playshift -g -f file -w 1 -m 1 -p maxbcnt

./playshift -g -f path/to/file
               -m mode
               -w word length
               -p player

./playshift -l -f path/to/file
               -m mode
               -w word length
               -p player


./playshift -l -f path/to/file
               -m mode1 mode2
               -w word length
               -p player

./playshift -b -f no3inrow
               -m mode1
               -w word length
               -p player

./playshift -g -f path/to/save/folder/prefix
               -n number_of_files
               -m mode1 mode2 (executes for each graph)
               -w word length
               -p player

rule
-b  to turn on
-f rule specified

// generators
-f prefix of path to store graphs

// random generator 
generated specified number of random graphs from universe of strongly connected graphs specified by number of nodes only so far... 
why? well that's how we can ensure that it's strongly connected.
-gg to turn on
-nn number_of_nodes 
-n number of graphs to generate

./playshift -gg -f path/to/save/folder/prefix -n 10 -nn 10

// universal generator 
generates all strongly connected graphs from universe of graphs specified by number of symbols with structure specified by number of edges, nodes or by pattern of undirected graph. 
Generated graphs can be filtered by specified filter.

// -n number_of_files are not needed
-ug to turn on
[-ns] number_of_symbols (2 if not specified)
[-gf] filter_name (no filter if not specified)
{ 
  -pf pattern_graph 
  | 
  -ne number_of_edges 
  -nn number_of_nodes 
}

./playshift -ug -f path/to/save/folder/prefix 
                -pf path/to/pattern_graph

./playshift -ug -f path/to/save/folder/prefix
                -ne number_of_edges
                -nn number_of_nodes

./playshift -ug -f path/to/save/folder/prefix
                -ne number_of_edges
                -nn number_of_nodes
                -ns number_of_symbols
                -gf filter_name


