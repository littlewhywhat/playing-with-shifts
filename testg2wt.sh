EXEC=testg2wt
RES=test/g2wt_res
DIFF=colordiff

echo "graph 3"
./$EXEC data/graph 3 > ./$RES
$DIFF ./$RES test/graph_3

rm -f $RES
