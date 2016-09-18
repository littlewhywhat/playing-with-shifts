EMPTY=data/empty
DATA=data/wt2ss
IN=$DATA/in
OUT=$DATA/out
EXEC=testwt2ss
RES=$DATA/res
DIFF=colordiff

g++ -std=c++11 src/$EXEC.cpp -o $EXEC

echo "full_in"
echo " - mode1"
./$EXEC $IN/full_in 3 1 > ./$RES
$DIFF ./$RES $OUT/full_out
echo " - mode2"
./$EXEC $IN/full_in 3 2 > ./$RES
$DIFF ./$RES $OUT/full_out

echo "input_wt0 100"
echo " - mode1"
./$EXEC $IN/input_wt0 3 1 > ./$RES
$DIFF ./$RES $OUT/output_wt01
echo " - mode2"
./$EXEC $IN/input_wt0 3 2 > ./$RES
$DIFF ./$RES $EMPTY

echo "input_wt1 101"
echo " - mode1"
./$EXEC $IN/input_wt1 3 1 > ./$RES
$DIFF ./$RES $OUT/output_wt11
echo " - mode2"
./$EXEC $IN/input_wt1 3 2 > ./$RES
$DIFF ./$RES $OUT/output_wt12

echo "input_wt2 101"
echo " - mode1"
./$EXEC $IN/input_wt2 3 1 > ./$RES
$DIFF ./$RES $OUT/output_wt21
echo " - mode2"
./$EXEC $IN/input_wt2 3 2 > ./$RES
$DIFF ./$RES $OUT/output_wt22

echo "input_wt3 110"
echo " - mode1"
./$EXEC $IN/input_wt3 3 1 > ./$RES
$DIFF ./$RES $OUT/output_wt31
echo " - mode2"
./$EXEC $IN/input_wt3 3 2 > ./$RES
$DIFF ./$RES $OUT/output_wt32

echo "input_wt4 110"
echo " - mode1"
./$EXEC $IN/input_wt4 3 1 > ./$RES
$DIFF ./$RES $OUT/output_wt41
echo " - mode2"
./$EXEC $IN/input_wt4 3 2 > ./$RES
$DIFF ./$RES $OUT/output_wt42

echo "input_wt5 011"
echo " - mode1"
./$EXEC $IN/input_wt5 3 1 > ./$RES
$DIFF ./$RES $OUT/output_wt51
echo " - mode2"
./$EXEC $IN/input_wt5 3 2 > ./$RES
$DIFF ./$RES $OUT/output_wt52

echo "input_wt6 011"
echo " - mode1"
./$EXEC $IN/input_wt6 3 1 > ./$RES
$DIFF ./$RES $OUT/output_wt61
echo " - mode2"
./$EXEC $IN/input_wt6 3 2 > ./$RES
$DIFF ./$RES $OUT/output_wt62

echo "input_wt7 100"
echo " - mode1"
./$EXEC $IN/input_wt7 3 1 > ./$RES
$DIFF ./$RES $OUT/output_wt71
echo " - mode2"
./$EXEC $IN/input_wt7 3 2 > ./$RES
$DIFF ./$RES $OUT/output_wt72

rm -f $RES; rm -f $EXEC
