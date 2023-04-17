echo "Prime numbers between 1 and 100 are:"
num1=1
while (( $num1 <= 100 ))
do
prime=1
i=2
while [ $i -lt $num1 ]
do
if [ $((num1 % i)) -eq 0 ]
then
prime=0
break
fi
i=$((i+1))
done
if [ $prime -eq 1 ]
then
echo "$num1"
fi
num1=$((num1 + 1))
done
