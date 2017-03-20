DATA=data/wt2ss
IN=$DATA/in
OUT=$DATA/out
EXEC=playshift
RES=$DATA/res
DIFF=colordiff

echo "full_in"
echo " - mode1"
./$EXEC -l $IN/full -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/full
echo " - mode2"
./$EXEC -l $IN/full -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/full
echo " - mode3"
./$EXEC -l $IN/full -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/full

echo "wt0 100"
echo " - mode1"
./$EXEC -l $IN/wt0 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt01
echo " - mode2"
./$EXEC -l $IN/wt0 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt02
echo " - mode3"
./$EXEC -l $IN/wt0 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt03

echo "wt1 101"
echo " - mode1"
./$EXEC -l $IN/wt1 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt11
echo " - mode2"
./$EXEC -l $IN/wt1 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt12
echo " - mode3"
./$EXEC -l $IN/wt1 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt13

echo "wt2 101"
echo " - mode1"
./$EXEC -l $IN/wt2 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt21
echo " - mode2"
./$EXEC -l $IN/wt2 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt22
echo " - mode3"
./$EXEC -l $IN/wt2 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt23

echo "wt3 110"
echo " - mode1"
./$EXEC -l $IN/wt3 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt31
echo " - mode2"
./$EXEC -l $IN/wt3 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt32

echo "wt4 110"
echo " - mode1"
./$EXEC -l $IN/wt4 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt41
echo " - mode2"
./$EXEC -l $IN/wt4 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt42
echo " - mode3"
./$EXEC -l $IN/wt4 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt43

echo "wt5 011"
echo " - mode1"
./$EXEC -l $IN/wt5 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt51
echo " - mode2"
./$EXEC -l $IN/wt5 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt52
echo " - mode3"
./$EXEC -l $IN/wt5 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt53

echo "wt6 011"
echo " - mode1"
./$EXEC -l $IN/wt6 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt61
echo " - mode2"
./$EXEC -l $IN/wt6 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt62
echo " - mode3"
./$EXEC -l $IN/wt6 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt63

echo "wt7 100"
echo " - mode1"
./$EXEC -l $IN/wt7 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt71
echo " - mode2"
./$EXEC -l $IN/wt7 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt72
echo " - mode3"
./$EXEC -l $IN/wt7 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt73

echo "wt8 001"
echo " - mode1"
./$EXEC -l $IN/wt8 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt81
echo " - mode2"
./$EXEC -l $IN/wt8 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt82
echo " - mode3"
./$EXEC -l $IN/wt8 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt83

echo "wt9 100"
echo " - mode1"
./$EXEC -l $IN/wt9 -w 3 -m 1 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt91
echo " - mode2"
./$EXEC -l $IN/wt9 -w 3 -m 2 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt92
echo " - mode3"
./$EXEC -l $IN/wt9 -w 3 -m 3 -nolang -test -nores > ./$RES
$DIFF ./$RES $OUT/wt93

rm -f $RES
