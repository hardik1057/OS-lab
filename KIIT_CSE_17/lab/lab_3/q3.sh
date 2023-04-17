if ([ $1 -gt $2 ] && [ $1 -gt $3 ])
then
echo "$1 is the greatest number"
if [ $2 -gt $3 ]
then
echo "$3 is the least number"
else
echo "$2 is the least number"
fi
elif ([ $2 -gt $1 ] && [ $2 -gt $3 ])
then
echo "$2 is the greatest number"
if [ $1 -gt $3 ]
then
echo "$3 is the least number"
else
echo "$1 is the least number"
fi
elif ([ $3 -gt $1 ] && [ $3 -gt $2 ])
then
echo "$3 is the greatest number"
if [ $2 -gt $1 ]
then
echo "$1 is the least number"
else
echo "$2 is the least number"
fi
fi

