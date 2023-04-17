#!/bin/bash
echo "Enter the first array- "
read -a array1
echo "Enter the second array- "
read -a array2
for i in "${array1[@]}"
do
  for j in "${array2[@]}"
  do
    if [[ "$i" == "$j" ]]; then
      echo $j
      break
    fi
  done
done