USAGE
==================

printer single parameters:

-nores don't output player max score
-nolang don't output language
-nogame don't output list of won strategies
-test output specific test prefixes
-filter output only specific rooms (ones with difference in max score)

arguments parser doesn't care if there are some useless arguments - as long as it can find necessary ones it will do the work.
all parameters are either single tags 

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

PLAYING WITH SUBSHIFTS
==================

Imagine a game with two opponents (A and B), a string of some length with open positions to fill in
and a predefined language or set of words with the same length as a string.
Each player has its own unique positions to fill that are prescribed by strategy.
They play in turns (the order is specified by game mode).

`Aim of A` - fill its positions in a such manner that resulting word will be in a language.

`Aim of B` - opposite - fill its positions to make some word out of a language.

Successful strategy is a strategy that doesn't allow B to win.

So far three game modes are considered:
1. Player B plays its positions first;
2. Player B plays its positions second;
3. Player B and player A play the game by order specified by strategy,

This application can construct a language for a game using a graph, file with words or class.
Then it performs computations on language in a specified game mode using other options provided by user.

## Build

C++11

run the following command in shell from root folder:

`make` (build and run)

or 

`make compile` (build)

Please use Q button to exit bash "less" (to remove "(END)" that appears after compilation)

Both will build an execution file 'playshift' in root folder.

## Graph format

first line is number of nodes.
from second line program starts to read edges with startnode, endnode and label 
specified through comma. Counting of nodes starts from 0.

Example:
```
4 
1,0,1
```
Graph with 4 nodes and one edge from node 1 to 0 with label 1.

## Run

```
usage: playshift -g graph_path | -b class_name | -l lang_path |
                -lf lang_folder | -gf graph_folder -m [1..3] -w [1..63]  
                [ -p player_name -gs gameserver_name -nores -nolang] 
                | -gg path_with_prefix -nn num_nodes -n num_graphs
                [-g graph_path | -b class_name | -l lang_path |
                -lf lang_folder | -gf graph_folder -m [1..3] -w [1..63]  
                [ -p player_name -gs gameserver_name -nores -nolang]]
```



## Examples

To start you can try example graphs in 'data' folder:

`make run`

or

`./playshift -g data/g2wt/in/graph1 -w 3 -p maxbcnt -m 1`

will produce the following output:
```
language:
111
101
110
011
010


good strategies are:
100
101
max = 2
```
other examples:

- compute on language of specified graph in mode 1 and
output language with all successful strategies:
```
./playshift -g data/g2wt/in/graph1 -m 1 -w 3
```

- compute language of specified builder class and
output language with all successful strategies:
```
./playshift -b no3inrow -m 1 -w 3
```

- compute language of specified set of words and
output language with all successful strategies:
```
./playshift -l data/wt2ss/in/wt0 -m 1 -w 3
```

- generate graphs:
```
./playshift -gg tmp/graph -nn 5 -n 5
```

## Test

To run all tests you can use the following command:

```
make test
```

The program consists of two parts: 
 * translating of graph to wordtable(language) 
```
    ./testg2wt.sh
```

 * computation of strategies using wordtable
```
    ./testwt2ss.sh
```

There is also script for testing the whole application:
```
    ./test.sh
```

The commands will compile special execution files for each case,
read some data in data folder and test outputs of graph translation or
computation algorithm for mode1 and mode2.

WARNING: this option requires `colordiff` installed on your machine. 
You can change DIFF variable in both shell scripts to usual `diff` that 
is usually installed by default
