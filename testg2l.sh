DATA=data/g2wt
EXEC=playshift
RES=$DATA/res
DIFF='diff'
SORT='sort'
IN=$DATA/in
OUT=$DATA/out

function sdiff {
	$DIFF <($SORT $1) <($SORT $2)
}

function test {
    echo $1
    ./$EXEC -g $IN/graph$2 -w $3 -m $4 -nores -test -nogame > ./$RES
    sdiff $RES $OUT/$1
}

test graph1_1_1 1 1 1 
test graph1_1_2 1 1 3
test graph1_2_1 1 2 1
test graph1_2_2 1 2 3
test graph1_3_1 1 3 1
test graph1_3_2 1 3 3
test graph1_4_1 1 4 1
test graph1_4_2 1 4 3
test graph1_5_1 1 5 1
test graph1_5_2 1 5 3

test graph2_1_1 2 1 1
test graph2_1_2 2 1 3
test graph2_2_1 2 2 1
test graph2_2_2 2 2 3
test graph2_3_1 2 3 1
test graph2_3_2 2 3 3
test graph2_4_1 2 4 1
test graph2_4_2 2 4 3
test graph2_5_1 2 5 1
test graph2_5_2 2 5 3

rm -f $RES

