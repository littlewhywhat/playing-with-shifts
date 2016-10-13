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