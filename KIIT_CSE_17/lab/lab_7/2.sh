#!/bin/bash
echo "Enter 5 elements into array- "
read -a arr
array=("${arr[@]:0:5}")
echo "The array you entered is:"
for element in "${array[@]}"
do
  echo "$element"
done
