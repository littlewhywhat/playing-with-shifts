DATA=data/wt2ss
IN=$DATA/in
OUT=$DATA/out
EXEC=testwt2ss
RES=$DATA/res
DIFF=colordiff

if g++ -std=c++11 src/$EXEC.cpp -o $EXEC; then

    echo "full_in"
    echo " - mode1"
    ./$EXEC $IN/full 3 1 > ./$RES
    $DIFF ./$RES $OUT/full
    echo " - mode2"
    ./$EXEC $IN/full 3 2 > ./$RES
    $DIFF ./$RES $OUT/full
    echo " - mode3"
    ./$EXEC $IN/full 3 3 > ./$RES
    $DIFF ./$RES $OUT/full

    echo "wt0 100"
    echo " - mode1"
    ./$EXEC $IN/wt0 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt01
    echo " - mode2"
    ./$EXEC $IN/wt0 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt02
    echo " - mode3"
    ./$EXEC $IN/wt0 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt03

    echo "wt1 101"
    echo " - mode1"
    ./$EXEC $IN/wt1 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt11
    echo " - mode2"
    ./$EXEC $IN/wt1 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt12
    echo " - mode3"
    ./$EXEC $IN/wt1 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt13

    echo "wt2 101"
    echo " - mode1"
    ./$EXEC $IN/wt2 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt21
    echo " - mode2"
    ./$EXEC $IN/wt2 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt22
    echo " - mode3"
    ./$EXEC $IN/wt2 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt23

    echo "wt3 110"
    echo " - mode1"
    ./$EXEC $IN/wt3 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt31
    echo " - mode2"
    ./$EXEC $IN/wt3 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt32

    echo "wt4 110"
    echo " - mode1"
    ./$EXEC $IN/wt4 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt41
    echo " - mode2"
    ./$EXEC $IN/wt4 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt42
    echo " - mode3"
    ./$EXEC $IN/wt4 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt43

    echo "wt5 011"
    echo " - mode1"
    ./$EXEC $IN/wt5 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt51
    echo " - mode2"
    ./$EXEC $IN/wt5 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt52
    echo " - mode3"
    ./$EXEC $IN/wt5 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt53

    echo "wt6 011"
    echo " - mode1"
    ./$EXEC $IN/wt6 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt61
    echo " - mode2"
    ./$EXEC $IN/wt6 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt62
    echo " - mode3"
    ./$EXEC $IN/wt6 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt63

    echo "wt7 100"
    echo " - mode1"
    ./$EXEC $IN/wt7 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt71
    echo " - mode2"
    ./$EXEC $IN/wt7 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt72
    echo " - mode3"
    ./$EXEC $IN/wt7 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt73

    echo "wt8 001"
    echo " - mode1"
    ./$EXEC $IN/wt8 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt81
    echo " - mode2"
    ./$EXEC $IN/wt8 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt82
    echo " - mode3"
    ./$EXEC $IN/wt8 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt83

    echo "wt9 100"
    echo " - mode1"
    ./$EXEC $IN/wt9 3 1 > ./$RES
    $DIFF ./$RES $OUT/wt91
    echo " - mode2"
    ./$EXEC $IN/wt9 3 2 > ./$RES
    $DIFF ./$RES $OUT/wt92
    echo " - mode3"
    ./$EXEC $IN/wt9 3 3 > ./$RES
    $DIFF ./$RES $OUT/wt93

    rm -f $RES; rm -f $EXEC

fi
