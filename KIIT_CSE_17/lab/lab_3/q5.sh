num=$1
if [ $num -le 1 ]; then
  echo "$num is not a prime number."
  exit
fi

x=2
flag=0
while [ $x -lt $num ]
do
  r=$((num % x))
  if [ $r -eq 0 ]; then
    flag=1
    break
  fi
  x=$((x + 1))
done

if [ $flag -eq 0 ]; then
  echo "$num is a prime number."
else
  echo "$num is not a prime number."
fi

