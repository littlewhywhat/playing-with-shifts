DATA=data
EXEC=playshift
RES=$DATA/app/res
IN=$DATA/g2wt/in
OUT=$DATA/app/out
SORT=sort

function sorteddiff {
	colordiff <($SORT $1) <($SORT $2)
}

DIFF=sorteddiff

echo "graph1_1_1"
./$EXEC -g $IN/graph1 -w 1 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_1_1

echo "graph1_1_2"
./$EXEC -g $IN/graph1 -w 1 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_1_2

echo "graph1_1_3"
./$EXEC -g $IN/graph1 -w 1 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_1_3

echo "graph1_2_1"
./$EXEC -g $IN/graph1 -w 2 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_2_1

echo "graph1_2_2"
./$EXEC -g $IN/graph1 -w 2 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_2_2

echo "graph1_2_3"
./$EXEC -g $IN/graph1 -w 2 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_2_3

echo "graph1_3_1"
./$EXEC -g $IN/graph1 -w 3 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_3_1

echo "graph1_3_2"
./$EXEC -g $IN/graph1 -w 3 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_3_2

echo "graph1_3_3"
./$EXEC -g $IN/graph1 -w 3 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_3_3

echo "graph1_4_1"
./$EXEC -g $IN/graph1 -w 4 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_4_1

echo "graph1_4_2"
./$EXEC -g $IN/graph1 -w 4 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_4_2

echo "graph1_4_3"
./$EXEC -g $IN/graph1 -w 4 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_4_3

echo "graph1_5_1"
./$EXEC -g $IN/graph1 -w 5 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_5_1

echo "graph1_5_2"
./$EXEC -g $IN/graph1 -w 5 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_5_2

echo "graph1_5_3"
./$EXEC -g $IN/graph1 -w 5 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph1_5_3

echo "graph2_1_1"
./$EXEC -g $IN/graph2 -w 1 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_1_1

echo "graph2_1_2"
./$EXEC -g $IN/graph2 -w 1 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_1_2

echo "graph2_1_3"
./$EXEC -g $IN/graph2 -w 1 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_1_3

echo "graph2_2_1"
./$EXEC -g $IN/graph2 -w 2 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_2_1

echo "graph2_2_2"
./$EXEC -g $IN/graph2 -w 2 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_2_2

echo "graph2_2_3"
./$EXEC -g $IN/graph2 -w 2 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_2_3

echo "graph2_3_1"
./$EXEC -g $IN/graph2 -w 3 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_3_1

echo "graph2_3_2"
./$EXEC -g $IN/graph2 -w 3 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_3_2

echo "graph2_3_3"
./$EXEC -g $IN/graph2 -w 3 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_3_3

echo "graph2_4_1"
./$EXEC -g $IN/graph2 -w 4 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_4_1

echo "graph2_4_2"
./$EXEC -g $IN/graph2 -w 4 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_4_2

echo "graph2_4_3"
./$EXEC -g $IN/graph2 -w 4 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_4_3

echo "graph2_5_1"
./$EXEC -g $IN/graph2 -w 5 -m 1 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_5_1

echo "graph2_5_2"
./$EXEC -g $IN/graph2 -w 5 -m 2 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_5_2

echo "graph2_5_3"
./$EXEC -g $IN/graph2 -w 5 -m 3 -p maxbcnt > ./$RES
$DIFF ./$RES $OUT/graph2_5_3

rm -f $RES
