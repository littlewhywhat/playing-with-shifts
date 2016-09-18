PLAYING WITH SUBSHIFTS
==================

Imagine a game with two opponents (A and B), a string of some length with open positions to fill in
and a predefined language or set of words with the same length as a string.
Each player has its own unique positions to fill that are prescribed by strategy.
They play in turns (concretely specified by game mode).
Aim of A - fill its positions in a such manner that resulting word will be in a language.
Aim of B - opposite - fill its positions to make some word out of a language.

According to game mode strategy can be called successfull.

This application takes in a graph, based on it produces a language of defined length
and find max number of positions in successful strategy that could be given to B.

####Build

run the following command in shell from root folder:
'''
make 
'''
it will build an execution file program in root folder.

####Run

run the following command in shell from root folder:
'''
./program path_to_graph length_of_language game_mode
'''

where length_of_language is some positive integer 
(after 10 in current version answer could take time :)) 

and game_mode is either 1 or 2.
