DATA=data/g2wt
EXEC=testg2wt
RES=$DATA/res
DIFF=colordiff
IN=$DATA/in
OUT=$DATA/out

g++ -std=c++11 src/$EXEC.cpp -o $EXEC

echo "graph1_1"
./$EXEC $IN/graph1 1 > ./$RES
$DIFF ./$RES $OUT/graph1_1

echo "graph1_2"
./$EXEC $IN/graph1 2 > ./$RES
$DIFF ./$RES $OUT/graph1_2

echo "graph1_3"
./$EXEC $IN/graph1 3 > ./$RES
$DIFF ./$RES $OUT/graph1_3

echo "graph1_4"
./$EXEC $IN/graph1 4 > ./$RES
$DIFF ./$RES $OUT/graph1_4

echo "graph1_5"
./$EXEC $IN/graph1 5 > ./$RES
$DIFF ./$RES $OUT/graph1_5

echo "graph2_1"
./$EXEC $IN/graph2 1 > ./$RES
$DIFF ./$RES $OUT/graph2_1

echo "graph2_2"
./$EXEC $IN/graph2 2 > ./$RES
$DIFF ./$RES $OUT/graph2_2

echo "graph2_3"
./$EXEC $IN/graph2 3 > ./$RES
$DIFF ./$RES $OUT/graph2_3

echo "graph2_4"
./$EXEC $IN/graph2 4 > ./$RES
$DIFF ./$RES $OUT/graph2_4

echo "graph2_5"
./$EXEC $IN/graph2 5 > ./$RES
$DIFF ./$RES $OUT/graph2_5
rm -f $RES; rm -f $EXEC

