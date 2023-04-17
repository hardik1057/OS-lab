num1=`grep -r $1 | cut -d " " -f 3`
num2=`grep -r $1 | cut -d " " -f 4`
num3=`grep -r $1 | cut -d " " -f 5`
num4=`grep -r $1 | cut -d " " -f 6`
num5=`grep -r $1 | cut -d " " -f 7`
total=$((num1 + num2 + num3 + num4 + num5))
percentage=$((total / 5))
echo "Total marks secured by the student- " $total
echo "Percentage obtained by the student- " $percentage


