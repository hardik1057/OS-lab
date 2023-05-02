num1=$1
num2=$2
if [ $(($num2 % $num1)) -eq 0 ]
then
  quotient=$(($num1 / $num2))
  echo "The quotient of $num1 divided by $num2 is $quotient"
elif [ $(($num2 % 5)) -eq 0 ]
then
  product=$(($num1 * $num2))
  echo "The product of $num1 and $num2 is $product"
else
  sum=$(($num1 + $num2))
  echo "The sum of $num1 and $num2 is $sum"
fi