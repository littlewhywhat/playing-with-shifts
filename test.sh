DATA=data
EXEC=program
RES=$DATA/app/res
DIFF=colordiff
IN=$DATA/g2wt/in
OUT=$DATA/app/out

g++ -std=c++11 src/$EXEC.cpp -o $EXEC

echo "graph1_1_1"
./$EXEC $IN/graph1 1 1 > ./$RES
$DIFF ./$RES $OUT/graph1_1_1

echo "graph1_1_2"
./$EXEC $IN/graph1 1 2 > ./$RES
$DIFF ./$RES $OUT/graph1_1_2

echo "graph1_2_1"
./$EXEC $IN/graph1 2 1 > ./$RES
$DIFF ./$RES $OUT/graph1_2_1

echo "graph1_2_2"
./$EXEC $IN/graph1 2 2 > ./$RES
$DIFF ./$RES $OUT/graph1_2_2

echo "graph1_3_1"
./$EXEC $IN/graph1 3 1 > ./$RES
$DIFF ./$RES $OUT/graph1_3_1

echo "graph1_3_2"
./$EXEC $IN/graph1 3 2 > ./$RES
$DIFF ./$RES $OUT/graph1_3_2

echo "graph1_4_1"
./$EXEC $IN/graph1 4 1 > ./$RES
$DIFF ./$RES $OUT/graph1_4_1

echo "graph1_4_2"
./$EXEC $IN/graph1 4 2 > ./$RES
$DIFF ./$RES $OUT/graph1_4_2

echo "graph1_5_1"
./$EXEC $IN/graph1 5 1 > ./$RES
$DIFF ./$RES $OUT/graph1_5_1

echo "graph1_5_2"
./$EXEC $IN/graph1 5 2 > ./$RES
$DIFF ./$RES $OUT/graph1_5_2

echo "graph2_1_1"
./$EXEC $IN/graph2 1 1 > ./$RES
$DIFF ./$RES $OUT/graph2_1_1

echo "graph2_1_2"
./$EXEC $IN/graph2 1 2 > ./$RES
$DIFF ./$RES $OUT/graph2_1_2

echo "graph2_2_1"
./$EXEC $IN/graph2 2 1 > ./$RES
$DIFF ./$RES $OUT/graph2_2_1

echo "graph2_2_2"
./$EXEC $IN/graph2 2 2 > ./$RES
$DIFF ./$RES $OUT/graph2_2_2

echo "graph2_3_1"
./$EXEC $IN/graph2 3 1 > ./$RES
$DIFF ./$RES $OUT/graph2_3_1

echo "graph2_3_2"
./$EXEC $IN/graph2 3 2 > ./$RES
$DIFF ./$RES $OUT/graph2_3_2

echo "graph2_4_1"
./$EXEC $IN/graph2 4 1 > ./$RES
$DIFF ./$RES $OUT/graph2_4_1

echo "graph2_4_1"
./$EXEC $IN/graph2 4 2 > ./$RES
$DIFF ./$RES $OUT/graph2_4_2

echo "graph2_5_1"
./$EXEC $IN/graph2 5 1 > ./$RES
$DIFF ./$RES $OUT/graph2_5_1

echo "graph2_5_2"
./$EXEC $IN/graph2 5 2 > ./$RES
$DIFF ./$RES $OUT/graph2_5_2

rm -f $RES; rm -f $EXEC

