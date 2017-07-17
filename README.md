PLAYING WITH SUBSHIFTS
==================

Imagine a game with two opponents (A and B), a string of some length with open positions to fill in
and a predefined language or set of words with the same length as a string.
Each player has its own unique positions to fill that are prescribed by strategy.
They play in turns (the order is specified by game mode).

`Aim of A` - fill its positions in a such manner that resulting word will be in a language.

`Aim of B` - opposite - fill its positions to make some word out of a language.

Successful strategy is a strategy that doesn't allow B to win.

So far three game modes are considered (numbering corresponds to input argument options -m):
1. Player B plays its positions first;
2. Player B plays its positions second;
3. Player B and player A play the game by order specified by strategy,

This application can construct a language for a game using a graph, file with words or class.
Then it performs computations on language in a specified game mode using other options provided by user.
Moreover it can generate random graphs with specified number of nodes.

USAGE
==================

```
./playshift -f PATH_OR_ID 
            { { -g|-l -n NUM_FILES } | -b -w WORDLENGTH -m GAMEMODE 
              [-p PLAYER -nores -nolang -nogame -test -filter]} 
            | { -gg -nn NUM_NODES -n NUM_GRAPHS } 
```

**Quick examples:**

Play in game mode 1 on graph specified in 'file_graph' with word length of 10

(don't output language, use player that doesn't play strategies that has less B's than current maximum):
 
```
./playshift -g -f file_graph -w 10 -m 1 -nolang -p maxbcnt
```

Play same way as above but on 3 graphs specified by prefix 'file_graph':

```
./playshift -g -f file_graph -n 3 -w 10 -m 1 -nolang -p maxbcnt

equivalent to

./playshift -g -f file_graph0 -w 10 -m 1 -nolang -p maxbcnt
./playshift -g -f file_graph1 -w 10 -m 1 -nolang -p maxbcnt
./playshift -g -f file_graph2 -w 10 -m 1 -nolang -p maxbcnt

```

Generate 10 random graphs with 10 nodes each:

```
./playshift -gg -f path/to/existing/folder/prefix -n 10 -nn 10

```

After to play in game mode 3 on all 10 generated graphs run:

```
./playshift -g -f path/to/existing/folder/prefix -n 10 -w 10 -m 3 -nolang -p maxbcnt
```

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

Example (graph with 4 nodes and one edge from node 1 to 0 with label 1):
```
4 
1,0,1
```