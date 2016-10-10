DATA=data/g2wt
EXEC=testg2l
RES=$DATA/res
DIFF=colordiff
IN=$DATA/in
OUT=$DATA/out

if g++ -std=c++11 src/main.cpp -o $EXEC;
then
    echo "graph1_1_1"
    ./$EXEC -g $IN/graph1 -w 1 -m 1 -p langout -nores -nolang > ./$RES
    $DIFF ./$RES $OUT/graph1_1_1

    echo "graph1_1_2"
    ./$EXEC -g $IN/graph1 -w 1 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_1_2

    echo "graph1_2_1"
    ./$EXEC -g $IN/graph1 -w 2 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_2_1

    echo "graph1_2_2"
    ./$EXEC -g $IN/graph1 -w 2 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_2_2

    echo "graph1_3_1"
    ./$EXEC -g $IN/graph1 -w 3 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_3_1

    echo "graph1_3_2"
    ./$EXEC -g $IN/graph1 -w 3 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_3_2

    echo "graph1_4_1"
    ./$EXEC -g $IN/graph1 -w 4 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_4_1

    echo "graph1_4_2"
    ./$EXEC -g $IN/graph1 -w 4 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_4_2

    echo "graph1_5_1"
    ./$EXEC -g $IN/graph1 -w 5 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_5_1

    echo "graph1_5_2"
    ./$EXEC -g $IN/graph1 -w 5 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph1_5_2

    echo "graph2_1_1"
    ./$EXEC -g $IN/graph2 -w 1 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_1_1

    echo "graph2_1_2"
    ./$EXEC -g $IN/graph2 -w 1 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_1_2

    echo "graph2_2_1"
    ./$EXEC -g $IN/graph2 -w 2 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_2_1

    echo "graph2_2_2"
    ./$EXEC -g $IN/graph2 -w 2 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_2_2

    echo "graph2_3_1"
    ./$EXEC -g $IN/graph2 -w 3 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_3_1

    echo "graph2_3_2"
    ./$EXEC -g $IN/graph2 -w 3 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_3_2

    echo "graph2_4_1"
    ./$EXEC -g $IN/graph2 -w 4 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_4_1

    echo "graph2_4_2"
    ./$EXEC -g $IN/graph2 -w 4 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_4_2

    echo "graph2_5_1"
    ./$EXEC -g $IN/graph2 -w 5 -m 1 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_5_1

    echo "graph2_5_2"
    ./$EXEC -g $IN/graph2 -w 5 -m 3 -p langout -nolang -nores > ./$RES
    $DIFF ./$RES $OUT/graph2_5_2
    rm -f $RES; rm -f $EXEC
fi
