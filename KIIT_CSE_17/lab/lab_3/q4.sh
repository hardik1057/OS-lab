res=`expr $1 % 2`
if [ $res -eq 0 ]
then
  echo "$1 is an even number."
else
  echo "$1 is an odd number."
fi
