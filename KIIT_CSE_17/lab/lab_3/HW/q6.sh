leap=$1
if [ $((leap % 400)) -eq 0 ]
then
if [ $((leap % 100)) -eq 0 ]
then
if [ $((leap % 4)) -eq 0 ]
then
echo "$leap is leap year"
else
echo "$leap is not a leap year"
fi
else
echo "$leap is not a leap year"
fi
else 
echo "$leap is leap year"
fi

