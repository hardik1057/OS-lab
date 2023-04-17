#!/bin/bash
echo "Enter elements into array- "
read -a array
echo "The array you entered is- "
for element in "${array[@]}"
do
  echo "$element"
done
sum=0
for element in "${array[@]}"
do
  sum=$((sum+element))
done
average=$((sum/${#array[@]}))
echo "The average of the array is: $average"