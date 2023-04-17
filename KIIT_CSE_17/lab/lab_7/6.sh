read -p "Enter the size of the array:" n
i=0
declare -a arr
while [ $i -lt $n ]
do
let i=i+1
read -p "Enter $i element of the array:" e
arr+=($e)
done
echo ${arr[@]}
read -p "Enter the index where you want to insert the new element:" e
declare -a ar
ar+=(${arr[@]:0:e})
read -p "Enter the  new element:" a
ar+=($a)
while [ $e -lt $n ]
do
ar+=(${arr[e]})
let e=e+1
done
echo ${ar[@]}