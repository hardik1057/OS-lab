i=0
echo "1) + 2) - 3) * 4) /"
while [ $i -eq 0 ]
do
echo "Enter your choice @ to terminate"
read ch
case $ch in
+) res=`expr $1 + $2`
echo "Summation of the numbers is $res"
;;
-) res=`expr $1 - $2`
echo "Subtraction of the numbers is $res"
;;
\*) res=`expr $1 \* $2`
echo "Multiplication of the numbers is $res"
;;
/) res=`expr $1 / $2`
echo "Division of the numbers is $res"
;;
@) i=1
;;
*) echo "Invalid Choice"
;;
esac
done

