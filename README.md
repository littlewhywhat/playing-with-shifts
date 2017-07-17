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

## Build

C++11

run the following command in shell from root folder:

`make` (build and run)

or 

`make compile` (build)

Please use Q button to exit bash "less" (to remove "(END)" that appears after compilation)

Both will build an execution file 'playshift' in root folder.

## USAGE

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

To read more about options please see USAGE.md.

**Input file format**

*Graphs*

first line is number of nodes.
from second line program starts to read edges with startnode, endnode and label 
specified through comma. Counting of nodes starts from 0.

Example (graph with 4 nodes and one edge from node 1 to 0 with label 1):
```
4 
1,0,1
```

*Language*

put each binary word on a separate line.

Example (language with 3 words: 001, 010, 100):
```
001
010
100
```

**Output format** 

Let's play on language built by rule no 3 ones in a row with word length 4 in mode 3.

Corresponding command will be:
```
./playshift -b -f no3inrow -w 3 -m 3
```

Output will be:
```
language: // list of words in language that was played on
000
001
010
011
100
101
110

no3inrow // source id 
good strategies are: // list of successful strategies
100
010
110
001
101
011
max = 2 // maximum number of B's in successful strategies
```
