EXEC=subsh
WORDLEN=3
MODE=1
SUBSH=0

if g++ -std=c++11 src/$EXEC.cpp -o $EXEC;
then
    ./$EXEC $WORDLEN $MODE $SUBSH
fi
