g++ make.cpp -o make --std=c++11
g++ Emy.cpp -o Emy --std=c++11
g++ Eans.cpp -o Eans --std=c++11
echo "compile finish"
while true
do
./make > E.in
./Emy < E.in > out1
./Eans < E.in > ans
if cmp -s out1 ans
then
echo Accepted
else echo Wrong
    cat out1
    cat ans
    break;
fi
echo "running"
done
exit
