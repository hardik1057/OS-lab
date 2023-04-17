echo "Enter the marks of the student:- "
read a
if [ $a -gt 90 -a $a -lt 100 ]
then
        echo "O"
elif [ $a -gt 80 -a $a -lt 89 ]
then
        echo "E"
elif [ $a -gt 70 -a $a -lt 79 ]
then
        echo "A"
elif [ $a -gt 60 -a $a -lt 69 ]
then
        echo "B"
elif [ $a -gt 50 -a $a -lt 59 ]
then
        echo "C"
elif [ $a -gt 40 -a $a -lt 49 ]
then
        echo "D"
elif [ $a -gt 0 -a $a -lt 39 ]
then
        echo "F"
fi

