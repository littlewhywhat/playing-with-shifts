PLAYING WITH SUBSHIFTS
==================

Imagine a game with two opponents (A and B), a string of some length with open positions to fill in
and a predefined language or set of words with the same length as a string.
Each player has its own unique positions to fill that are prescribed by strategy.
They play in turns (concretely specified by game mode).
Aim of A - fill its positions in a such manner that resulting word will be in a language.
Aim of B - opposite - fill its positions to make some word out of a language.

According to game mode strategy can be called successfull.

This application takes in a graph with labeled edges (so far only '1' or '0' labels are supported),
based on it produces a language of defined length
and find max number of positions in successful strategy that could be given to B.

## Build

C++11

run the following command in shell from root folder:

`make`

or 

`make compile`

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

run the following command in shell from root folder:

`./program path_to_graph length_of_language game_mode`

where length_of_language is some positive integer 
(after 10 in current version answer could take time :)) 

and game_mode is either 1 or 2.

## Example

To start you can try example graphs in 'data' folder:

`make run`

or

`./program data/graph 3 1`

will produce the following output:
```
Building wordtable...
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
 * computation of strategies using wordtable

There are no tests for first part.
To execute test for second part, use:

`make test`

The command will compile special tprogram execution file,
read some prespecified wordtables in test folder and test outputs 
of computation algorithm for mode1 and mode2.

WARNING: this option requires colordiff installed on your machine.