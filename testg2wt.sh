DATA=data/g2wt
EXEC=testg2wt
RES=$DATA/res
DIFF=colordiff

g++ -std=c++11 src/$EXEC.cpp -o $EXEC

echo "graph 3"
./$EXEC $DATA/graph 3 > ./$RES
$DIFF ./$RES $DATA/graph_3

rm -f $RES; rm -f $EXEC
