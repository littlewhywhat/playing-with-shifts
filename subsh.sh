EXEC=subsh
WORDLEN=3
MODE=1
SUBSH=0

g++ -std=c++11 src/$EXEC.cpp -o $EXEC 

./$EXEC $WORDLEN $MODE $SUBSH
