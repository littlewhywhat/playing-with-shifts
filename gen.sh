EXEC=modediff
GFOLDER=tmp
CNT_NODES=5
CNT_GRAPHS=10
M_CODE1=1
M_CODE2=3
WORDLEN=10

if g++ -std=c++11 src/$EXEC.cpp -o $EXEC;
then
    rm -f -r $GFOLDER
    mkdir $GFOLDER
    ./$EXEC $GFOLDER/graph $CNT_NODES $CNT_GRAPHS $M_CODE1 $M_CODE2 $WORDLEN
fi
