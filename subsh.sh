EXEC=subsh
WORDLEN=3
MODE=1
SUBSH=no3inrow

if g++ -std=c++11 src/$EXEC.cpp -o $EXEC 2>&1 | less;
then
    ./$EXEC $WORDLEN $MODE $SUBSH
fi
