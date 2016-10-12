PLAYING WITH SUBSHIFTS
==================

Imagine a game with two opponents (A and B), a string of some length with open positions to fill in
and a predefined language or set of words with the same length as a string.
Each player has its own unique positions to fill that are prescribed by strategy.
They play in turns (concretely specified by game mode).

`Aim of A` - fill its positions in a such manner that resulting word will be in a language.

`Aim of B` - opposite - fill its positions to make some word out of a language.

According to game mode strategy can be called successfull.

This application takes in a graph with labeled edges (`only '1' or '0' labels are supported`),
based on it produces a language of defined length
and find max number of positions in successful strategy that could be given to B.

## Modes
Application accepts three kinds of modes:

- Mode1 `(src/mode1.h)`:
B plays its positions first. Applications tries to find for every possible value in set of B positions 
at least one word in the wordtable.

Example:
```
Wordtable:
000
100
010

Successful strategies:
100
010

Bad strategy:
001

```

- Mode2 `(src/mode2.h)`:
B plays its positions second. Applications tries to find for every possible value in set of B positions 
a set of words in the wordtable that differ only in B positions.

Example:
```
Wordtable:
000
100
010

Successful strategies:
100

Bad strategy:
010
001
```

- Mode3 `(src/mode3.h)`:
A and B play one after another and sequence of turns is determined by strategy from left to right.
Applications builds a wordtree from graph and tries to check in each node 
(in another words, for every possible situation in the game) if there are successful ways of playing for A or if
any play of B is successful for A.

Example:
```
Wordtree:
000
100
010

Successful strategies:
100
010

Bad strategy:
001
```

## Build

C++11

run the following command in shell from root folder:

`make` (build and run)

or 

`make compile` (build)

Please use Q button to exit bash "less" (to remove "(END)" that appears after compilation)

Both will build an execution file 'program' in root folder.

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

usage: playshift -g graph_path | -b class_name | -l lang_path |
                -lf lang_folder | -gf graph_folder -m [1..3] -w [1..63]  
                [ -p player_name -gs gameserver_name -nores -nolang] 
                | -gg path_with_prefix -nn num_nodes -n num_graphs
                [-g graph_path | -b class_name | -l lang_path |
                -lf lang_folder | -gf graph_folder -m [1..3] -w [1..63]  
                [ -p player_name -gs gameserver_name -nores -nolang]]

example of commands to try:

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
mkdir tmp;
./playshift -gg tmp/graph -nn 5 -n 5
```

- generate graphs and compare them in modes 1 and 3:

```
mkdir tmp;
./playshift -gg tmp/graph -nn 5 -n 5 -w 10 -m 1 -m 3 -gs diff -p maxbcnt
-nolang -nores
```

## Example

To start you can try example graphs in 'data' folder:

`make run`

or

`./program data/graph 3 1`

will produce the following output:
```
Building worddata...
001
010
101
110
100
000
011


good strategies are:
100
110
max = 2
```

## Test
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

To run all tests you can use the following command:

`make test`
