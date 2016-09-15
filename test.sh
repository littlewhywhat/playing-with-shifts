echo "full_in"
echo " - mode1"
./program test/full_in 3 1 > ./bin/res
colordiff ./bin/res test/full_out
echo " - mode2"
./program test/full_in 3 2 > ./bin/res
colordiff ./bin/res test/full_out

echo "input_wt0 100"
echo " - mode1"
./program test/input_wt0 3 1 > ./bin/res
colordiff ./bin/res test/output_wt01
echo " - mode2"
./program test/input_wt0 3 2 > ./bin/res
colordiff ./bin/res test/empty

echo "input_wt1 101"
echo " - mode1"
./program test/input_wt1 3 1 > ./bin/res
colordiff ./bin/res test/output_wt11
echo " - mode2"
./program test/input_wt1 3 2 > ./bin/res
colordiff ./bin/res test/output_wt12

echo "input_wt2 101"
echo " - mode1"
./program test/input_wt2 3 1 > ./bin/res
colordiff ./bin/res test/output_wt21
echo " - mode2"
./program test/input_wt2 3 2 > ./bin/res
colordiff ./bin/res test/output_wt22

echo "input_wt3 110"
echo " - mode1"
./program test/input_wt3 3 1 > ./bin/res
colordiff ./bin/res test/output_wt31
echo " - mode2"
./program test/input_wt3 3 2 > ./bin/res
colordiff ./bin/res test/output_wt32

echo "input_wt4 110"
echo " - mode1"
./program test/input_wt4 3 1 > ./bin/res
colordiff ./bin/res test/output_wt41
echo " - mode2"
./program test/input_wt4 3 2 > ./bin/res
colordiff ./bin/res test/output_wt42

echo "input_wt5 011"
echo " - mode1"
./program test/input_wt5 3 1 > ./bin/res
colordiff ./bin/res test/output_wt51
echo " - mode2"
./program test/input_wt5 3 2 > ./bin/res
colordiff ./bin/res test/output_wt52

echo "input_wt6 011"
echo " - mode1"
./program test/input_wt6 3 1 > ./bin/res
colordiff ./bin/res test/output_wt61
echo " - mode2"
./program test/input_wt6 3 2 > ./bin/res
colordiff ./bin/res test/output_wt62

echo "input_wt7 100"
echo " - mode1"
./program test/input_wt7 3 1 > ./bin/res
colordiff ./bin/res test/output_wt71
echo " - mode2"
./program test/input_wt7 3 2 > ./bin/res
colordiff ./bin/res test/output_wt72
